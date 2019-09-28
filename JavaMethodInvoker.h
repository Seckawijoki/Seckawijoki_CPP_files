#ifndef JAVA_METHOD_INVOKER_H
#define JAVA_METHOD_INVOKER_H
#include "AndroidMethodHolder.h"
#include "OgreSingleton.h"
#include <vector>
using namespace lua2java;
using std::vector;
class JavaMethodInvokerBuilder{//tolua_exports
public:
	JavaMethodInvokerBuilder();
	~JavaMethodInvokerBuilder();
	//tolua_begin
	JavaMethodInvokerBuilder* debug(const bool);
	JavaMethodInvokerBuilder* setClassName(const char*);
	JavaMethodInvokerBuilder* setMethodName(const char*);
	JavaMethodInvokerBuilder* setSignature(const char*);
	JavaMethodInvokerBuilder* addBoolean(bool);
	JavaMethodInvokerBuilder* addByte(char);
	JavaMethodInvokerBuilder* addChar(const char*);
	JavaMethodInvokerBuilder* addShort(short);
	JavaMethodInvokerBuilder* addInt(int);
	JavaMethodInvokerBuilder* addLong(long);
	JavaMethodInvokerBuilder* addFloat(float);
	JavaMethodInvokerBuilder* addDouble(double);
	JavaMethodInvokerBuilder* addString(const char*);
	JavaMethodInvokerBuilder* clearParams();
	JavaMethodInvokerBuilder* callAndroidMethod();
	JavaMethodInvokerBuilder* call();
	bool getBoolean();
	char getByte();
	const char* getChar();
	short getShort();
	int getInt();
	long getLong();
	float getFloat();
	double getDouble();
	const char* getString();
	//tolua_end
	bool isUsed();
	void onRecycle();
	void print();
public:
	JavaMethodInvokerBuilder* m_pNext;
private:
	std::vector<Holder> m_AndroidParams;
	Holder* m_pReturnHolder;
	const char* m_szClassName;
	const char* m_szMethodName;
	const char* m_szSignature;
	Type m_JavaReturnType;
	bool m_bDebug;
	bool m_bIsUsed;
};//tolua_exports
extern JavaMethodInvokerBuilder* newAndroidMethodInvokerBuilder();//tolua_export
class JavaMethodInvokerFactory //tolua_exports
	: public Ogre::Singleton<JavaMethodInvokerFactory> 
{//tolua_exports
public:
	//tolua_begin
	JavaMethodInvokerBuilder* newAppPlayBaseActivityStaticMethodInvoker();
	JavaMethodInvokerBuilder* newGameActivityStaticMethodInvoker();
	JavaMethodInvokerBuilder* newStaticMethodInvoker();
	JavaMethodInvokerBuilder* obtain();
	void release();
	void printAll();
	//tolua_end
	/**
	* 加入链表头
	*/
	void add(JavaMethodInvokerBuilder* node);
private:
	/**
	* 链表头
	*/
	static JavaMethodInvokerBuilder* s_Pool;
	static int s_PoolSize;
	static int MAX_POOL_SIZE;
};//tolua_exports
#endif