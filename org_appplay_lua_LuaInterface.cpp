#include "org_appplay_lua_LuaInterface.h"
#include "LuaFunctionInvoker.h"
#include "JNICommonUtils.h"
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    obtain
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_org_appplay_lua_LuaInterface_obtain
  (JNIEnv *, jclass){
    if (!LuaFunctionInvokerFactory::getSingletonPtr()){
        return 0;
    }
    LuaFunctionInvokerBuilder* builder = LuaFunctionInvokerFactory::getSingleton().obtain();
    LOGD("obtain(): builder = %x", builder);
    long address = (long)&(*builder);
    LOGD("obtain(): address = %x", address);
    return address;
  }

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    getTable
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_getTable
  (JNIEnv *env, jclass, jlong pNativeClassAddress, jstring jstrTableName){
    LuaFunctionInvokerBuilder* builder = reinterpret_cast<LuaFunctionInvokerBuilder*>(pNativeClassAddress);
    LOGD("getTable(): builder = %x", builder);
    std::string strTableName = j2c(env, jstrTableName);
    LOGD("getTable(): strTableName.c_str() = %s", strTableName.c_str());
    const char* szTableName = strTableName.c_str();
    LOGD("getTable(): szTableName = %s", szTableName);
    return builder->getTable(szTableName) == JNI_TRUE;
  }

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    getFunction
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_getFunction
  (JNIEnv *env, jclass, jlong pNativeClassAddress, jstring jstrFunctionName){
    LuaFunctionInvokerBuilder* builder = reinterpret_cast<LuaFunctionInvokerBuilder*>(pNativeClassAddress);
    std::string strFunctionName = j2c(env, jstrFunctionName);
    const char* szFunctionName = strFunctionName.c_str();
    LOGD("getTable(): szFunctionName = %s", szFunctionName);
    return builder->getFunction(szFunctionName) == JNI_TRUE;
  }

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    getSelfFunction
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_getSelfFunction
  (JNIEnv *env, jclass, jlong pNativeClassAddress, jstring jstrFunctionName){
    LuaFunctionInvokerBuilder* builder = reinterpret_cast<LuaFunctionInvokerBuilder*>(pNativeClassAddress);
    std::string strFunctionName = j2c(env, jstrFunctionName);
    const char* szFunctionName = strFunctionName.c_str();
    LOGD("getSelfFunction(): szFunctionName = %s", szFunctionName);
    return builder->getSelfFunction(szFunctionName) == JNI_TRUE;
  }

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    pushBoolean
 * Signature: (JZ)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_pushBoolean
  (JNIEnv *, jclass, jlong pNativeClassAddress, jboolean z){
    LuaFunctionInvokerBuilder* builder = reinterpret_cast<LuaFunctionInvokerBuilder*>(pNativeClassAddress);
    return builder->pushBoolean(z) == JNI_TRUE;
  }

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    pushNumber
 * Signature: (JD)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_pushNumber
  (JNIEnv *, jclass, jlong pNativeClassAddress, jdouble db){
    LuaFunctionInvokerBuilder* builder = reinterpret_cast<LuaFunctionInvokerBuilder*>(pNativeClassAddress);
    return builder->pushNumber(db) == JNI_TRUE;
  }

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    pushString
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_pushString
  (JNIEnv *env, jclass, jlong pNativeClassAddress, jstring jstr){
    LuaFunctionInvokerBuilder* builder = reinterpret_cast<LuaFunctionInvokerBuilder*>(pNativeClassAddress);
    std::string str = j2c(env, jstr);
    return builder->pushString(str) == JNI_TRUE;
  }

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    setReturnCount
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_appplay_lua_LuaInterface_setReturnCount
  (JNIEnv *, jclass, jlong pNativeClassAddress, jint iReturnCount){
    LuaFunctionInvokerBuilder* builder = reinterpret_cast<LuaFunctionInvokerBuilder*>(pNativeClassAddress);
    int i = iReturnCount;
    builder->setReturnCount(i);
  }

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    setReturnTypes
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_org_appplay_lua_LuaInterface_setReturnTypes
  (JNIEnv *env, jclass, jlong pNativeClassAddress, jstring retTypes){
    LuaFunctionInvokerBuilder* builder = reinterpret_cast<LuaFunctionInvokerBuilder*>(pNativeClassAddress);
    std::string strReturnTypes = j2c(env, retTypes);
    LOGD("setReturnTypes(): strReturnTypes.c_str() = %s", strReturnTypes.c_str());
    builder->m_strReturnTypes = strReturnTypes;
    int len = strReturnTypes.size();
    LOGD("setReturnTypes(): len = %d", len);
    builder->setReturnCount(len);
    return true;
  }

/*
 * Class:     org_appplay_lua_LuaInterface
 * Method:    call
 * Signature: (J)Lorg/appplay/lua/LuaReturnValues;
 */
JNIEXPORT jobject JNICALL Java_org_appplay_lua_LuaInterface_call
  (JNIEnv *env, jclass, jlong pNativeClassAddress){
    LuaFunctionInvokerBuilder* builder = reinterpret_cast<LuaFunctionInvokerBuilder*>(pNativeClassAddress);
    LOGW("call(): before call");
    builder->printStack();
    builder->call();
    LOGW("call(): after call");
    builder->printStack();
    const char* szReturnTypes = builder->m_strReturnTypes.c_str();
    jclass jclass_LuaReturnValues = env->FindClass("org/appplay/lua/LuaReturnValues");
    jobject jobject_LuaReturnValues;
    jmethodID mid;
    
    if (!jclass_LuaReturnValues){
        LOGE("call(): Cannot get java Class: LuaReturnValues.");
        builder->popTables();
        return NULL;
    }

    mid = env->GetMethodID(jclass_LuaReturnValues, "<init>", "()V");
    if (!mid){
        env->DeleteLocalRef(jclass_LuaReturnValues);
        LOGE("call(): Cannot get LuaReturnValues's constructor.");
        builder->popTables();
        return NULL;
    }

    jobject_LuaReturnValues = env->NewObject(jclass_LuaReturnValues, mid);
    if (!jobject_LuaReturnValues){
        env->DeleteLocalRef(jclass_LuaReturnValues);
        LOGE("call(): Cannot create an instance of LuaReturnValues.");
        builder->popTables();
        return NULL;
    }

    jboolean z;
    jdouble db;
    jstring jstr;
    const char* sz;
    while (*szReturnTypes){
        LOGD("call(): *szReturnTypes = %c", *szReturnTypes);
        switch (*szReturnTypes){
            case LuaReturnTypes::JAVA2LUA_BOOLEAN:
                mid = env->GetMethodID(jclass_LuaReturnValues, "addBoolean", "(Z)V");
                if (!mid){
                    env->DeleteLocalRef(jclass_LuaReturnValues);
                    env->DeleteLocalRef(jobject_LuaReturnValues);
                    env->DeleteLocalRef(jstr);
                    LOGE("call(): Cannot get member method addBoolean.");
                    builder->popTables();
                    return NULL;
                }
                z = builder->popBoolean();
                LOGD("call(): z = %d", z);
                env->CallVoidMethod(jobject_LuaReturnValues, mid, z);
                break;
            case LuaReturnTypes::JAVA2LUA_NUMBER:
                mid = env->GetMethodID(jclass_LuaReturnValues, "addNumber", "(D)V");
                if (!mid){
                    env->DeleteLocalRef(jclass_LuaReturnValues);
                    env->DeleteLocalRef(jobject_LuaReturnValues);
                    env->DeleteLocalRef(jstr);
                    LOGE("call(): Cannot get member method addNumber.");
                    builder->popTables();
                    return NULL;
                }
                db = builder->popNumber();
                LOGD("call(): db = %llf", db);
                env->CallVoidMethod(jobject_LuaReturnValues, mid, db);
                break;
            case LuaReturnTypes::JAVA2LUA_STRING:
                mid = env->GetMethodID(jclass_LuaReturnValues, "addString", "(Ljava/lang/String;)V");
                if (!mid){
                    env->DeleteLocalRef(jclass_LuaReturnValues);
                    env->DeleteLocalRef(jobject_LuaReturnValues);
                    env->DeleteLocalRef(jstr);
                    LOGE("call(): Cannot get member method addString.");
                    builder->popTables();
                    return NULL;
                }
                sz = builder->popString();
                LOGD("call(): sz = %s", sz);
                jstr = env->NewStringUTF(sz);
                env->CallVoidMethod(jobject_LuaReturnValues, mid, jstr);
                break;
            default:
                return NULL;
        }
        ++szReturnTypes;
    }
    env->DeleteLocalRef(jclass_LuaReturnValues);
    // LOGD("call(): DeleteLocalRef(jclass_LuaReturnValues)");
    env->DeleteLocalRef(jstr);
    // LOGD("call(): DeleteLocalRef(jstr)");
    builder->popTables();
    LOGW("call(): after pop");
    builder->printStack();
    builder->recycle();
    LOGW("call(): builder->recycle()");
    return jobject_LuaReturnValues;
  }

#ifdef __cplusplus
}
#endif
