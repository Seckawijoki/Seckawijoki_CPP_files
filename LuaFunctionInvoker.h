#ifndef __LUA_FUNCTION_INVOKER__
#define __LUA_FUNCTION_INVOKER__

#include "OgreScriptLuaVM.h"
#include "OgreSingleton.h"
#include "OgreLog.h"
struct lua_State;
enum LuaReturnTypes {
	JAVA2LUA_BOOLEAN = '1',
	JAVA2LUA_NUMBER = '2',
	JAVA2LUA_STRING = '3',
};
class LuaFunctionInvokerBuilder {
public:
	LuaFunctionInvokerBuilder();
	~LuaFunctionInvokerBuilder();
	bool setLuaVirtualMachine(Ogre::ScriptVM* pScriptVM);
	bool getTable(const char* szTableName);
	bool getFunction(const char* szFunctionName);
	bool getSelfFunction(const char* szFunctionName);
	bool pushBoolean(bool b);
	bool pushNumber(int i);
	bool pushNumber(double db);
	bool pushNumber(float f);
	bool pushString(const char* sz);
	bool pushString(std::string str);
	bool setReturnCount(int iReturnCount);
	bool call();
	bool checkCanPop();
	bool popBoolean();
	double popNumber();
	const char* popString();
	void popTables();
	void printStack(int depth = 0);
	bool isUsed();
	void recycle();
	void onRecycle();
	void print();
public:
	LuaFunctionInvokerBuilder* m_pNext;
	std::string m_strReturnTypes;
private:
	lua_State* m_pLuaStack;
	int m_iParamCount;
	int m_iReturnCount;
	int m_iTableDepth;
	int m_iErrorCode;
	bool m_bHasGotGlobal;
	bool m_bHasGotTable;
	bool m_bHasGotFunction;
	bool m_bIsUsed;
};
class LuaFunctionInvokerFactory : //tolua_exports
	public Ogre::Singleton<LuaFunctionInvokerFactory>
{//tolua_exports
public:
	LuaFunctionInvokerBuilder* obtain();
	LuaFunctionInvokerFactory* setLuaVirtualMachine(Ogre::ScriptVM* pScript);
	void release();
	void printAll();
	/**
	* 加入链表头
	*/
	void add(LuaFunctionInvokerBuilder* node);
	//tolua_begin
	void test00();
	//tolua_end
private:
	Ogre::ScriptVM* m_pScriptVM;
	/**
	* 链表头
	*/
	static LuaFunctionInvokerBuilder* s_Pool;
	static int s_iPoolSize;
	static int MAX_POOL_SIZE;
};//tolua_exports
#endif //__LUA_FUNCTION_INVOKER__