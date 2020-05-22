#include "JavaMethodInvoker.h"
#include "AndroidMethodHolder.h"
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#include "AppPlayJNI.hpp"
#endif//OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#include "OgreLog.h"
using namespace lua2java;
JavaMethodInvokerBuilder::JavaMethodInvokerBuilder()
	:m_bDebug(false), m_bIsUsed(false), m_JavaReturnType(JAVA_VOID), m_pNext(NULL), m_pReturnHolder(NULL), m_szClassName(NULL), m_szMethodName(NULL), m_szSignature(NULL)
{
	m_bDebug = false;
	m_bIsUsed = false;
}
JavaMethodInvokerBuilder::~JavaMethodInvokerBuilder() {
	m_AndroidParams.clear();
	m_pNext = NULL;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::debug(bool debug) {
	m_bDebug = debug;
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::setClassName(const char* className) {
	if (m_bDebug)LOG_INFO("setClassName(): className = %s", className);
	m_szClassName = className;
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::setMethodName(const char* methodName) {
	if (m_bDebug)LOG_INFO("setClassName(): methodName = %s", methodName);
	m_szMethodName = methodName;
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::setSignature(const char* signature) {
	if (m_bDebug)LOG_INFO("setSignature(): signature = %s", signature);
	if (!signature){
		return this;
	}
	m_szSignature = signature;
	std::string szSignature = std::string(signature);
	std::string szSignatureReturnType = szSignature.substr(szSignature.find_last_of(')') + 1);
	if (m_bDebug)LOG_INFO("setSignature(): szSignatureReturnType = %s", szSignatureReturnType.c_str());
	m_JavaReturnType = JAVA_VOID;
	if (szSignatureReturnType.compare("V") == 0) {
		m_JavaReturnType = JAVA_VOID;
	}
	else if (szSignatureReturnType.compare("Z") == 0) {
		m_JavaReturnType = JAVA_BOOLEAN;
	}
	else if (szSignatureReturnType.compare("B") == 0) {
		m_JavaReturnType = JAVA_BYTE;
	}
	else if (szSignatureReturnType.compare("C") == 0) {
		m_JavaReturnType = JAVA_CHAR;
	}
	else if (szSignatureReturnType.compare("S") == 0) {
		m_JavaReturnType = JAVA_SHORT;
	}
	else if (szSignatureReturnType.compare("I") == 0) {
		m_JavaReturnType = JAVA_INT;
	}
	else if (szSignatureReturnType.compare("J") == 0) {
		m_JavaReturnType = JAVA_LONG;
	}
	else if (szSignatureReturnType.compare("F") == 0) {
		m_JavaReturnType = JAVA_FLOAT;
	}
	else if (szSignatureReturnType.compare("D") == 0) {
		m_JavaReturnType = JAVA_DOUBLE;
	}
	else if (szSignatureReturnType.compare("Ljava/lang/String;") == 0) {
		m_JavaReturnType = JAVA_STRING;
	}
	//else if (szSignatureReturnType.compare("L") == 0) {
	//	  m_JavaReturnType = JAVA_OBJECT;
	//}
	if (m_bDebug)LOG_INFO("setSignature(): m_JavaReturnType = %d", m_JavaReturnType);
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::addBoolean(bool b) {
	if (m_bDebug)LOG_INFO("addBoolean(): bool = %d", b);
	m_AndroidParams.push_back(Holder(JAVA_BOOLEAN, b));
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::addByte(char c) {
	if (m_bDebug)LOG_INFO("addByte(): byte = %d", c);
	m_AndroidParams.push_back(Holder(JAVA_BYTE, c));
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::addChar(const char* c) {
	if (m_bDebug)LOG_INFO("addChar(): c = %c", c[0]);
	m_AndroidParams.push_back(Holder(JAVA_CHAR, c[0]));
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::addShort(short sh) {
	if (m_bDebug)LOG_INFO("addShort(): sh = %d", sh);
	m_AndroidParams.push_back(Holder(JAVA_SHORT, sh));
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::addInt(int i) {
	if (m_bDebug)LOG_INFO("addInt(): i = %d", i);
	m_AndroidParams.push_back(Holder(JAVA_INT, i));
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::addLong(long l) {
	if (m_bDebug)LOG_INFO("addLong(): l = %ld", l);
	m_AndroidParams.push_back(Holder(JAVA_LONG, l));
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::addFloat(float f) {
	if (m_bDebug)LOG_INFO("addFloat(): f = %f", f);
	m_AndroidParams.push_back(Holder(JAVA_FLOAT, f));
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::addDouble(double db) {
	if (m_bDebug)LOG_INFO("addDouble(): db = %lf", db);
	m_AndroidParams.push_back(Holder(JAVA_DOUBLE, db));
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::addString(const char* cstr) {
	if (m_bDebug)LOG_INFO("addString(): cstr = %s", cstr);
	m_AndroidParams.push_back(Holder(JAVA_STRING, std::string(cstr)));
	return this;
}
//JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::addIntArray(int is[]) {
//	LOG_INFO("addInt(): is = %d", is);
//	m_AndroidParams.push_back(Holder(JAVA_INT_ARRAY, is));
//	return this;
//}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::clearParams() {
	m_AndroidParams.clear();
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::callAndroidMethod() {
	if (m_bDebug)LOG_INFO("callAndroidMethod(): m_JavaReturnType = %d", m_JavaReturnType);
	if (!m_szClassName || !m_szMethodName || !m_szSignature){
		m_bIsUsed = true;
		m_pReturnHolder = new Holder(JAVA_VOID);
		return this;
	}
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	m_pReturnHolder = CallAndroidMethodJNI(m_szClassName, m_szMethodName, m_szSignature, m_JavaReturnType, m_AndroidParams, m_bDebug);
#else
	m_pReturnHolder = new Holder(JAVA_VOID);
#endif
	m_bIsUsed = true;
	return this;
}
JavaMethodInvokerBuilder* JavaMethodInvokerBuilder::call() {
	if (m_bDebug)LOG_INFO("callAndroidMethod(): m_JavaReturnType = %d", m_JavaReturnType);
#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
	m_pReturnHolder = CallAndroidMethodJNI(m_szClassName, m_szMethodName, m_szSignature, m_JavaReturnType, m_AndroidParams, m_bDebug);
#else
	m_pReturnHolder = new Holder(JAVA_VOID);
#endif
	m_bIsUsed = true;
	JavaMethodInvokerFactory::getSingleton().add(this);
	return this;
}
bool JavaMethodInvokerBuilder::getBoolean() {
	if (m_bDebug)LOG_INFO("getBoolean(): m_JavaReturnType = %d | m_pReturnHolder->getType() = %d", m_JavaReturnType, m_pReturnHolder->getType());
	return m_pReturnHolder && m_JavaReturnType == m_pReturnHolder->getType() && m_JavaReturnType == JAVA_BOOLEAN ? m_pReturnHolder->get<bool>() : false;
}
char JavaMethodInvokerBuilder::getByte() {
	if (m_bDebug)LOG_INFO("getByte(): m_JavaReturnType = %d | m_pReturnHolder->getType() = %d", m_JavaReturnType, m_pReturnHolder->getType());
	return m_pReturnHolder && m_JavaReturnType == m_pReturnHolder->getType() && m_JavaReturnType == JAVA_BYTE ? m_pReturnHolder->get<char>() : 0;
}
const char* JavaMethodInvokerBuilder::getChar() {
	if (m_bDebug)LOG_INFO("getChar(): m_JavaReturnType = %d | m_pReturnHolder->getType() = %d", m_JavaReturnType, m_pReturnHolder->getType());
	if (m_pReturnHolder && m_JavaReturnType == m_pReturnHolder->getType() && m_JavaReturnType == JAVA_CHAR) {
		char* cstr = new char[2];
		cstr[0] = m_pReturnHolder->get<char>();
		cstr[1] = '\0';
		return cstr;
	} else {
		return "";
	}
}
short JavaMethodInvokerBuilder::getShort() {
	if (m_bDebug)LOG_INFO("getShort(): m_JavaReturnType = %d | m_pReturnHolder->getType() = %d", m_JavaReturnType, m_pReturnHolder->getType());
	return m_pReturnHolder && m_JavaReturnType == m_pReturnHolder->getType() && m_JavaReturnType == JAVA_SHORT ? m_pReturnHolder->get<short>() : 0;
}
int JavaMethodInvokerBuilder::getInt() {
	if (m_bDebug)LOG_INFO("getInt(): m_JavaReturnType = %d | m_pReturnHolder->getType() = %d", m_JavaReturnType, m_pReturnHolder->getType());
	return m_pReturnHolder && m_JavaReturnType == m_pReturnHolder->getType() && m_JavaReturnType == JAVA_INT ? m_pReturnHolder->get<int>() : 0;
}
long JavaMethodInvokerBuilder::getLong() {
	if (m_bDebug)LOG_INFO("getLong(): m_JavaReturnType = %d | m_pReturnHolder->getType() = %d", m_JavaReturnType, m_pReturnHolder->getType());
	return m_pReturnHolder && m_JavaReturnType == m_pReturnHolder->getType() && m_JavaReturnType == JAVA_LONG ? m_pReturnHolder->get<long>() : 0;
}
float JavaMethodInvokerBuilder::getFloat() {
	if (m_bDebug)LOG_INFO("getFloat(): m_JavaReturnType = %d | m_pReturnHolder->getType() = %d", m_JavaReturnType, m_pReturnHolder->getType());
	return m_pReturnHolder && m_JavaReturnType == m_pReturnHolder->getType() && m_JavaReturnType == JAVA_FLOAT ? m_pReturnHolder->get<float>() : 0;
}
double JavaMethodInvokerBuilder::getDouble() {
	if (m_bDebug)LOG_INFO("getDouble(): m_JavaReturnType = %d | m_pReturnHolder->getType() = %d", m_JavaReturnType, m_pReturnHolder->getType());
	return m_pReturnHolder && m_JavaReturnType == m_pReturnHolder->getType() && m_JavaReturnType == JAVA_DOUBLE ? m_pReturnHolder->get<double>() : 0;
}
const char* JavaMethodInvokerBuilder::getString() {
	if (m_bDebug)LOG_INFO("getString(): m_JavaReturnType = %d | m_pReturnHolder->getType() = %d", m_JavaReturnType, m_pReturnHolder->getType());
	return m_pReturnHolder && m_JavaReturnType == m_pReturnHolder->getType() && m_JavaReturnType == JAVA_STRING ? m_pReturnHolder->get<std::string>().c_str() : "";
}
bool JavaMethodInvokerBuilder::isUsed() {
	return m_bIsUsed;
}
void JavaMethodInvokerBuilder::onRecycle() {
	clearParams();
	m_pNext = NULL;
	m_bIsUsed = false;
	m_bDebug = false;
}
void JavaMethodInvokerBuilder::print() {
	//LOG_INFO("print(): next = %x : %s %s %s (isUsed = %d), ", 
	//	m_pNext ? m_pNext : 0, 
	//	m_szClassName ? m_szClassName : "",
	//	m_szMethodName ? m_szMethodName : "",
	//	m_szSignature ? m_szSignature : "",
	//	m_bIsUsed
	//);
}

JavaMethodInvokerBuilder* newAndroidMethodInvokerBuilder(){
	// LOG_INFO("newAndroidMethodInvokerBuilder():");
	return new JavaMethodInvokerBuilder();
}
//=============================================JavaMethodInvokerFactory=============================================
int JavaMethodInvokerFactory::MAX_POOL_SIZE = 50;
int JavaMethodInvokerFactory::s_PoolSize = 0;
JavaMethodInvokerBuilder* JavaMethodInvokerFactory::s_Pool = NULL;
JavaMethodInvokerBuilder* JavaMethodInvokerFactory::newAppPlayBaseActivityStaticMethodInvoker() {
	return obtain()->setClassName("org/appplay/lib/AppPlayBaseActivity");
}

JavaMethodInvokerBuilder* JavaMethodInvokerFactory::newGameActivityStaticMethodInvoker() {
	return obtain()->setClassName("org/appplay/lib/GameBaseActivity");
}

JavaMethodInvokerBuilder* JavaMethodInvokerFactory::newStaticMethodInvoker() {
	return new JavaMethodInvokerBuilder();
}

void JavaMethodInvokerFactory::release() {
	JavaMethodInvokerBuilder* current = s_Pool;
	JavaMethodInvokerBuilder* temp;
	while (current) {
		temp = current;
		current = current->m_pNext;
		if (temp != current) {
			OGRE_DELETE(temp);
		}
	}
}

void JavaMethodInvokerFactory::printAll() {
	LOG_INFO("printAll(): s_PoolSize = %d", s_PoolSize);
	JavaMethodInvokerBuilder* current = s_Pool;
	int count = 0;
	while (current) {
		++count;
		LOG_INFO("printAll(): [%d] = %x (isUsed = %d)", count, current, current->isUsed());
		current->print();
		current = current->m_pNext;
	}
}

void JavaMethodInvokerFactory::add(JavaMethodInvokerBuilder* node) {
	JavaMethodInvokerBuilder* head = s_Pool;
	if (!head) {
		s_Pool = node;
		++s_PoolSize;
		return;
	}
	head = node;
	head->m_pNext = s_Pool;
	s_Pool = head;
	++s_PoolSize;
}

JavaMethodInvokerBuilder* JavaMethodInvokerFactory::obtain() {
	if (!s_Pool) {
		JavaMethodInvokerBuilder* builder = new JavaMethodInvokerBuilder();
		//LOG_INFO("JavaMethodInvokerFactory::obtain(): new head @%x", builder);
		return s_Pool = builder;
	}
	//if (s_PoolSize > MAX_POOL_SIZE) {
	//	return new JavaMethodInvokerBuilder();
	//}
	JavaMethodInvokerBuilder* current = s_Pool;
	JavaMethodInvokerBuilder* previous = NULL;
	while (current->m_pNext) {
		if (current->isUsed()) {
			break;
		}
		previous = current;
		current = current->m_pNext;
	}
	if (!current->isUsed()) {
		JavaMethodInvokerBuilder* builder = new JavaMethodInvokerBuilder();
		//LOG_INFO("JavaMethodInvokerFactory::obtain(): new node @%x", builder);
		return builder;
	}
	if (previous) {
		previous->m_pNext = current->m_pNext;
		current->m_pNext = NULL;
	} else {
		s_Pool = NULL;
	}

	--s_PoolSize;
	current->onRecycle();
	//LOG_INFO("JavaMethodInvokerFactory::obtain(): reuse @%x", current);
	return current;
}