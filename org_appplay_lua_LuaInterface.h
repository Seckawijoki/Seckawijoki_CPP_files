/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_appplay_lua_LuaInterface */

#ifndef _Included_org_appplay_lua_LuaInterface
#define _Included_org_appplay_lua_LuaInterface
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    obtain
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_appplay_lua_LuaInterface_obtain
  (JNIEnv *, jclass);

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    getTable
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_getTable
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    getFunction
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_getFunction
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    getSelfFunction
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_getSelfFunction
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    pushBoolean
 * Signature: (JZ)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_pushBoolean
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    pushNumber
 * Signature: (JD)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_pushNumber
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    pushString
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_pushString
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    setReturnCount
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lua_LuaInterface_setReturnCount
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    setReturnTypes
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_setReturnTypes
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    call
 * Signature: (J)Lorg/appplay/lua/LuaReturnValues;
 */
JNIEXPORT jobject JNICALL Java_org_appplay_lua_LuaInterface_call
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
