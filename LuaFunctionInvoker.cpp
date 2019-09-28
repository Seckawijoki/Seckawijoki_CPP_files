#include "LuaFunctionInvoker.h"
#include "OgreLog.h"
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
#include "tolua++.h"
using namespace Ogre;
LuaFunctionInvokerBuilder::LuaFunctionInvokerBuilder() {
	m_pLuaStack = NULL;
	m_bHasGotGlobal = false;
	m_bHasGotTable = false;
	m_bHasGotFunction = false;
	m_iParamCount = 0;
	m_iReturnCount = 0;
	m_iTableDepth = 0;
	m_strReturnTypes = "";
}
LuaFunctionInvokerBuilder::~LuaFunctionInvokerBuilder() {
	m_pLuaStack = NULL;
	m_bHasGotGlobal = false;
	m_bHasGotTable = false;
	m_bHasGotFunction = false;
}
bool LuaFunctionInvokerBuilder::setLuaVirtualMachine(Ogre::ScriptVM* pScriptVM) {
	LOG_INFO("setLuaVirtualMachine(): pScriptVM = %x", pScriptVM);
	if (!pScriptVM) {
		LOG_INFO("setLuaVirtualMachine(): pScriptVM NULL");
		return false;
	}
	m_pLuaStack = pScriptVM->getLuaState();
}
bool LuaFunctionInvokerBuilder::getTable(const char* szTableName) {
	if (!m_pLuaStack) {
		LOG_INFO("getTable(): m_pLuaStack NULL");
		return false;
	}
	//lua_getfield(m_pLuaStack, -1, szTableName);
	if (m_bHasGotGlobal) {
		lua_getfield(m_pLuaStack, -1, szTableName);
	} else {
		lua_getglobal(m_pLuaStack, szTableName);
		m_bHasGotGlobal = true;
	}
	if (lua_isnil(m_pLuaStack, -1)) {
		LOG_INFO("getTable(): table %s is nil.", szTableName);
		m_iErrorCode = -1;
		return false;
	}
	if (!lua_istable(m_pLuaStack, -1)) {
		LOG_INFO("getTable(): %s is not a table.", szTableName);
		m_iErrorCode = -1;
		return false;
	}
	LOG_INFO("getTable(): get table : %s", szTableName);
	++m_iTableDepth;
	m_bHasGotTable = true;
	return true;
}
bool LuaFunctionInvokerBuilder::getSelfFunction(const char* szFunctionName) {
	LOG_INFO("getSelfFunction(): ");
	if (!getFunction(szFunctionName)) {
		return false;
	}
	if (m_bHasGotTable) {
		lua_pushvalue(m_pLuaStack, -2);
		++m_iParamCount;
	}
	return true;
}
bool LuaFunctionInvokerBuilder::getFunction(const char* szFunctionName) {
	LOG_INFO("getFunction(): szFunctionName = %s", szFunctionName);
	if (!m_pLuaStack) {
		LOG_INFO("getFunction(): m_pLuaStack NULL");
		return false;
	}
	//lua_pushstring(m_pLuaStack, szFunctionName);
	//lua_getglobal(m_pLuaStack, -2);
	if (m_bHasGotGlobal) {
		lua_getfield(m_pLuaStack, -1, szFunctionName);
	}
	else {
		lua_getglobal(m_pLuaStack, szFunctionName);
	}
	if (lua_isnil(m_pLuaStack, -1)) {
		LOG_INFO("getFunction(): function %s is nil.", szFunctionName);
		m_iErrorCode = -1;
		return false;
	}
	if (!lua_isfunction(m_pLuaStack, -1)) {
		LOG_INFO("getFunction(): %s is not a function.", szFunctionName);
		m_iErrorCode = -1;
		return false;
	}
	LOG_INFO("getFunction(): get function : %s", szFunctionName);
	return true;
}
bool LuaFunctionInvokerBuilder::pushBoolean(bool b) {
	if (!m_pLuaStack) {
		return false;
	}
	LOG_INFO("pushBoolean(): b = %d", b);
	lua_pushboolean(m_pLuaStack, b);
	printStack(3);
	++m_iParamCount;
	luaL_checkstack(m_pLuaStack, 1, "too many arguments");
	return true;
}
bool LuaFunctionInvokerBuilder::pushNumber(int i) {
	return pushNumber((int)i);
}
bool LuaFunctionInvokerBuilder::pushNumber(float f) {
	return pushNumber((double)f);
}
bool LuaFunctionInvokerBuilder::pushNumber(double db) {
	if (!m_pLuaStack) {
		return false;
	}
	LOG_INFO("pushNumber(): db = %llf", db);
	lua_pushnumber(m_pLuaStack, db);
	printStack(3);
	++m_iParamCount;
	luaL_checkstack(m_pLuaStack, 1, "too many arguments");
	return true;
}
bool LuaFunctionInvokerBuilder::pushString(const char* sz) {
	if (!m_pLuaStack) {
		return false;
	}
	LOG_INFO("pushString(): sz = %s", sz);
	lua_pushstring(m_pLuaStack, sz);
	printStack(3);
	++m_iParamCount;
	luaL_checkstack(m_pLuaStack, 1, "too many arguments");
	return true;
}
bool LuaFunctionInvokerBuilder::pushString(std::string str) {
	return pushString(str.c_str());
}
bool LuaFunctionInvokerBuilder::setReturnCount(int iReturnCount) {
	LOG_INFO("setReturnCount(): iReturnCount = %d", iReturnCount);
	if (!m_pLuaStack) {
		return false;
	}
	m_iReturnCount = iReturnCount;
	return true;
}
bool LuaFunctionInvokerBuilder::call() {
	if (!m_pLuaStack) {
		return false;
	}
	m_iErrorCode = lua_pcall(m_pLuaStack, m_iParamCount, m_iReturnCount, 0);
	LOG_INFO("LuaFunctionInvokerBuilder::call(): m_iErrorCode = %d", m_iErrorCode);
	if (m_iErrorCode != 0) {
		const char* szErrorMsg = lua_tostring(m_pLuaStack, -1);
		LOG_INFO("LuaFunctionInvokerBuilder::call(): lua_pcall catch : %s", szErrorMsg);
		LOG_PRIVATE("LuaFunctionInvokerBuilder::call(): lua_pcall catch : %s", szErrorMsg);
		printStack(m_iParamCount + m_iTableDepth + 3);
		return false;
	}
	return true;
}
bool LuaFunctionInvokerBuilder::checkCanPop() {
	if (!m_pLuaStack) {
		LOG_INFO("checkCanPop(): m_pLuaStack NULL");
		return false;
	}
	if (m_iReturnCount <= 0) {
		LOG_INFO("checkCanPop(): no more return values");
		return false;
	}
	if (m_iErrorCode != 0) {
		LOG_INFO("checkCanPop(): function calling in catch");
		return false;
	}
	return true;
}
bool LuaFunctionInvokerBuilder::popBoolean() {
	if (!checkCanPop()) {
		LOG_INFO("popBoolean(): return default false");
		return false;
	}
	if (!lua_isboolean(m_pLuaStack, -m_iReturnCount)) {
		LOG_INFO("popBoolean(): stack in -%d is not a boolean", m_iReturnCount);
		return false;
	}
	LOG_INFO("popBoolean(): before");
	printStack(m_iReturnCount);
	bool b = lua_toboolean(m_pLuaStack, -m_iReturnCount) != 0;
	LOG_INFO("popBoolean(): b = %d", b);
	--m_iReturnCount;
	printStack(m_iReturnCount);
	return b;
}
double LuaFunctionInvokerBuilder::popNumber() {
	if (!checkCanPop()) {
		LOG_INFO("popNumber(): return default 0");
		return 0;
	}
	if (!lua_isnumber(m_pLuaStack, -m_iReturnCount)) {
		LOG_INFO("popNumber(): stack in -%d is not a number", m_iReturnCount);
		return false;
	}
	LOG_INFO("popNumber(): before");
	printStack(m_iReturnCount);
	double db = lua_tonumber(m_pLuaStack, -m_iReturnCount);
	LOG_INFO("popNumber(): db = %llf", db);
	--m_iReturnCount;
	printStack(m_iReturnCount);
	return db;
}
const char* LuaFunctionInvokerBuilder::popString() {
	if (!checkCanPop()) {
		LOG_INFO("popString(): return default empty string");
		return "";
	}
	if (!lua_isstring(m_pLuaStack, -m_iReturnCount)) {
		LOG_INFO("popString(): stack in -%d is not a string", m_iReturnCount);
		return false;
	}
	LOG_INFO("popString(): before");
	printStack(m_iReturnCount);
	const char* sz = lua_tostring(m_pLuaStack, -m_iReturnCount);
	LOG_INFO("popString(): sz = %s", sz);
	--m_iReturnCount;
	printStack(m_iReturnCount);
	return sz;
}
void LuaFunctionInvokerBuilder::popTables() {
	if (!checkCanPop()) {
		return;
	}
	while (m_iReturnCount--) {
		lua_pop(m_pLuaStack, -1);
	}
	while (m_iTableDepth--){
		lua_pop(m_pLuaStack, -1);
	}
}
void LuaFunctionInvokerBuilder::printStack(int depth) {
	if (depth <= 0){
		depth = m_iTableDepth + m_iParamCount + m_iReturnCount + 3;
	}
	//LOG_INFO("printStack(): depth = %d", depth);
	const int top = lua_gettop(m_pLuaStack);
	//LOG_INFO("printStack(): top = %d", top);
	int type;
	for (int i = top; i >= 0 && depth > 0; --depth, --i) {
		type = lua_type(m_pLuaStack, i);
		switch (type){
		case LUA_TBOOLEAN:
			LOG_INFO("printStack(): [%d] = (boolean) %s ", i, lua_toboolean(m_pLuaStack, i) ? "true" : "false");
			break;
		case LUA_TNUMBER:
			LOG_INFO("printStack(): [%d] = (number) %llf ", i, lua_tonumber(m_pLuaStack, i));
			break;
		case LUA_TSTRING:
			LOG_INFO("printStack(): [%d] = (string) %s ", i, lua_tostring(m_pLuaStack, i));
			break;
		default:
			LOG_INFO("printStack(): [%d] = %s@%d ", i, lua_typename(m_pLuaStack, type), lua_topointer(m_pLuaStack, i));
			break;
		}
	}
}

bool LuaFunctionInvokerBuilder::isUsed() {
	return m_bIsUsed;
}
void LuaFunctionInvokerBuilder::recycle() {
	m_bIsUsed = true;
	LuaFunctionInvokerFactory::getSingleton().add(this);
}
void LuaFunctionInvokerBuilder::onRecycle() {
	m_bHasGotGlobal = false;
	m_bHasGotTable = false;
	m_bHasGotFunction = false;
	m_iParamCount = 0;
	m_iReturnCount = 0;
	m_iErrorCode = 0;
	m_strReturnTypes = "";
}
void LuaFunctionInvokerBuilder::print() {

}

//=============================================LuaFunctionInvokerFactory=============================================
class LuaFunctionInvokerBuilder;
int LuaFunctionInvokerFactory::MAX_POOL_SIZE = 50;
int LuaFunctionInvokerFactory::s_iPoolSize = 0;
LuaFunctionInvokerBuilder* LuaFunctionInvokerFactory::s_Pool = NULL;
void LuaFunctionInvokerFactory::release() {
	LuaFunctionInvokerBuilder* current = s_Pool;
	LuaFunctionInvokerBuilder* temp;
	while (current) {
		temp = current;
		current = current->m_pNext;
		OGRE_DELETE(temp);
	}
}

void LuaFunctionInvokerFactory::printAll() {
	LOG_INFO("printAll(): s_iPoolSize = %d", s_iPoolSize);
	LuaFunctionInvokerBuilder* current = s_Pool;
	int count = 0;
	while (current) {
		++count;
		LOG_INFO("printAll(): [%d] = %x (isUsed = %d)", count, current, current->isUsed());
		current->print();
		current = current->m_pNext;
	}
}

void LuaFunctionInvokerFactory::add(LuaFunctionInvokerBuilder* node) {
	LuaFunctionInvokerBuilder* head = s_Pool;
	if (!head) {
		s_Pool = node;
		++s_iPoolSize;
		return;
	}
	head = node;
	head->m_pNext = s_Pool;
	s_Pool = head;
	++s_iPoolSize;
}

LuaFunctionInvokerBuilder* LuaFunctionInvokerFactory::obtain() {
	if (!s_Pool) {
		LuaFunctionInvokerBuilder* builder = new LuaFunctionInvokerBuilder();
		builder->setLuaVirtualMachine(m_pScriptVM);
		LOG_INFO("LuaFunctionInvokerFactory::obtain(): new head @%x", builder);
		return s_Pool = builder;
	}
	//if (s_iPoolSize > MAX_POOL_SIZE) {
	//	return new LuaFunctionInvokerBuilder();
	//}
	LuaFunctionInvokerBuilder* current = s_Pool;
	LuaFunctionInvokerBuilder* previous = NULL;
	while (current->m_pNext) {
		if (current->isUsed()) {
			break;
		}
		previous = current;
		current = current->m_pNext;
	}
	if (!current->isUsed()) {
		LuaFunctionInvokerBuilder* builder = new LuaFunctionInvokerBuilder();
		builder->setLuaVirtualMachine(m_pScriptVM);
		LOG_INFO("LuaFunctionInvokerFactory::obtain(): new node @%x", builder);
		return builder;
	}
	if (previous) {
		previous->m_pNext = current->m_pNext;
		current->m_pNext = NULL;
	}
	else {
		s_Pool = NULL;
	}

	--s_iPoolSize;
	current->onRecycle();
	LOG_INFO("LuaFunctionInvokerFactory::obtain(): reuse @%x", current);
	return current;
}
LuaFunctionInvokerFactory* LuaFunctionInvokerFactory::setLuaVirtualMachine(Ogre::ScriptVM* pScript) {
	LOG_INFO("LuaFunctionInvokerFactory::setLuaVirtualMachine(): pScript = %x", pScript);
	m_pScriptVM = pScript;
	return this;
}
void LuaFunctionInvokerFactory::test00() {
	LuaFunctionInvokerBuilder* builder = obtain();
	builder->setLuaVirtualMachine(m_pScriptVM);
	builder->getTable("Android");
	builder->getTable("A");
	builder->getTable("BB");
	builder->getTable("CCC");
	builder->getSelfFunction("DDDD");
	//builder->getFunction("EEEEE");
	builder->pushBoolean(false);
	builder->pushNumber(1);
	builder->pushNumber(2.7f);
	builder->pushNumber(3.14);
	builder->pushString("c++");
	builder->setReturnCount(5);
	builder->call();
	const char* sz = builder->popString();
	double db = builder->popNumber();
	float f = builder->popNumber();
	int i = builder->popNumber();
	bool b = builder->popBoolean();
	LOG_INFO("testCallLua(): b = %d", b);
	LOG_INFO("testCallLua(): i = %d", i);
	LOG_INFO("testCallLua(): f = %f", f);
	LOG_INFO("testCallLua(): db = %llf", db);
	LOG_INFO("testCallLua(): sz = %s", sz);
}