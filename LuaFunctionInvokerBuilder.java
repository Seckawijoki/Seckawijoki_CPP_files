package org.appplay.lua;

import android.util.Log;

import java.util.Arrays;
public final class LuaFunctionInvokerBuilder {
    private static final String TAG = "LuaFunctionInvokerBuild";
    private static final boolean DEBUG = false;
    private String m_szFunctionName;
    private Class[] mReturnTypes;
    /**
     * c++ pointer address
     */
    private long pNativeBuilder;

    public LuaFunctionInvokerBuilder() {
        pNativeBuilder = LuaInterface.obtain();
        if ( pNativeBuilder == 0 ) {
            errorTip("Cannot create LuaFunctionInvokerBuilder");
        }
        Log.d(TAG, "LuaFunctionInvokerBuilder(): pNativeBuilder = " + Long.toHexString(pNativeBuilder));
    }

    public LuaFunctionInvokerBuilder debug(final boolean debug) {
        LuaInterface.debug(pNativeBuilder, debug);
        return this;
    }

    public LuaFunctionInvokerBuilder getTable(final String szClassName) {
        if ( !LuaInterface.getTable(pNativeBuilder, szClassName) ) {
            errorTip("Cannot get table: " + szClassName);
        }
        return this;
    }

    public LuaFunctionInvokerBuilder getFunction(final String szFunctionName) {
        if ( !LuaInterface.getFunction(pNativeBuilder, szFunctionName) ) {
            errorTip("Cannot get function: " + szFunctionName);
        }
        m_szFunctionName = szFunctionName;
        return this;
    }

    public LuaFunctionInvokerBuilder getSelfFunction(final String szFunctionName) {
        if ( !LuaInterface.getSelfFunction(pNativeBuilder, szFunctionName) ) {
            errorTip("Cannot get self function: " + szFunctionName);
        }
        m_szFunctionName = szFunctionName;
        return this;
    }

    public LuaFunctionInvokerBuilder pushBoolean(boolean z) {
        if ( !LuaInterface.pushBoolean(pNativeBuilder, z) ) {
            errorTip("Cannot push boolean: " + z);
        }
        return this;
    }

    public LuaFunctionInvokerBuilder pushNumber(double db) {
        if ( !LuaInterface.pushNumber(pNativeBuilder, db) ) {
            errorTip("Cannot push number: " + db);
        }
        return this;
    }

    public LuaFunctionInvokerBuilder pushString(String s) {
        if ( !LuaInterface.pushString(pNativeBuilder, s) ) {
            errorTip("Cannot push string: " + s);
        }
        return this;
    }

    public LuaFunctionInvokerBuilder setReturnTypes(Class... retTypes) {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("");
        for ( Class retType : retTypes ) {
            Log.d(TAG, "setReturnTypes(): retType = " + retType);
            if ( retType == Boolean.class ) {
                stringBuilder.append(LuaBasicTypes.BOOLEAN);
            } else if ( isLuaNumber(retType) ) {
                stringBuilder.append(LuaBasicTypes.NUMBER);
            } else if ( retType == String.class ) {
                stringBuilder.append(LuaBasicTypes.STRING);
            } else {
                errorTip("Not support lua return type: " + retType.getSimpleName());
            }
        }
        Log.d(TAG, "setReturnTypes(): stringBuilder = " + stringBuilder);
        if ( !LuaInterface.setReturnTypes(pNativeBuilder, stringBuilder.toString()) ) {
            errorTip("Set lua return types error: " + Arrays.toString(retTypes));
        }
        return this;
    }

    public LuaReturnValues call() {
        LuaReturnValues luaReturnValues = LuaInterface.call(pNativeBuilder);
        if ( luaReturnValues == null ) {
            errorTip("Lua return error from function " + m_szFunctionName);
        } else {
            luaReturnValues.setReturnTypes(mReturnTypes);
        }
        return luaReturnValues;
    }

    private static void errorTip(String tips) {
        if ( DEBUG ) {
            throw new LuaFunctionInvokerException(tips);
        } else {
            Log.e(TAG, tips);
        }
    }

    private static boolean isLuaNumber(Class numberCls) {
        return numberCls == Byte.class
                || numberCls == Short.class
                || numberCls == Integer.class
                || numberCls == Long.class
                || numberCls == Float.class
                || numberCls == Double.class;
    }

    public static void selfFunctionTest() {
        LuaReturnValues luaReturnValues = new LuaFunctionInvokerBuilder()
                .debug(true)
                .getTable("Android")
                .getTable("A")
                .getTable("BB")
                .getTable("CCC")
                .getSelfFunction("DDDD")
                .pushBoolean(false)
                .pushNumber(1)
                .pushNumber(2.7f)
                .pushNumber(3.14)
                .pushString("Java")
                .setReturnTypes(String.class, Double.class, Float.class, Integer.class, Boolean.class)
                .call();
        Log.d(TAG, "selfFunctionTest(): luaReturnValues = " + luaReturnValues);
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.<String>get(0) = " + luaReturnValues.<String>get(0));
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.<Double>get(1) = " + luaReturnValues.<Double>get(1));
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.<Float>get(2) = " + luaReturnValues.<Float>get(2));
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.<Integer>get(3) = " + luaReturnValues.<Integer>get(3));
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.<Boolean>get(4) = " + luaReturnValues.<Boolean>get(4));

        Log.d(TAG, "selfFunctionTest(): luaReturnValues.getString(0) = " + luaReturnValues.getString(0));
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.getNumber(1) = " + luaReturnValues.getNumber(1));
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.getNumber(2) = " + luaReturnValues.getNumber(2));
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.getNumber(3) = " + luaReturnValues.getNumber(3));
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.getBoolean(4) = " + luaReturnValues.getBoolean(4));

        Log.w(TAG, "selfFunctionTest(): luaReturnValues.getString(4) = " + luaReturnValues.getString(4));
        Log.w(TAG, "selfFunctionTest(): luaReturnValues.getNumber(0) = " + luaReturnValues.getNumber(0));
        Log.w(TAG, "selfFunctionTest(): luaReturnValues.getBoolean(1) = " + luaReturnValues.getBoolean(1));

        Log.d(TAG, "selfFunctionTest(): luaReturnValues.popString() = " + luaReturnValues.popString());
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.popNumber() = " + luaReturnValues.popNumber());
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.popNumber() = " + luaReturnValues.popNumber());
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.popNumber() = " + luaReturnValues.popNumber());
        Log.d(TAG, "selfFunctionTest(): luaReturnValues.popBoolean() = " + luaReturnValues.popBoolean());

        Log.w(TAG, "selfFunctionTest(): luaReturnValues.popString() = " + luaReturnValues.popString());
        Log.w(TAG, "selfFunctionTest(): luaReturnValues.popNumber() = " + luaReturnValues.popNumber());
        Log.w(TAG, "selfFunctionTest(): luaReturnValues.popBoolean() = " + luaReturnValues.popBoolean());
    }

    public static void functionTest() {
        LuaReturnValues luaReturnValues = new LuaFunctionInvokerBuilder()
                .getTable("Android")
                .getTable("A")
                .getTable("BB")
                .getTable("CCC")
                .debug(true)
                .getFunction("EEEEE")
                .debug(false)
                .pushBoolean(false)
                .pushNumber(1)
                .pushNumber(2.7f)
                .pushNumber(3.14)
                .pushString("Java")
                .setReturnTypes(String.class, Double.class, Float.class, Integer.class, Boolean.class)
                .debug(true)
                .call();
        Log.d(TAG, "functionTest(): luaReturnValues = " + luaReturnValues);
        Log.d(TAG, "functionTest(): luaReturnValues.<String>get(0) = " + luaReturnValues.<String>get(0));
        Log.d(TAG, "functionTest(): luaReturnValues.<Double>get(1) = " + luaReturnValues.<Double>get(1));
        Log.d(TAG, "functionTest(): luaReturnValues.<Float>get(2) = " + luaReturnValues.<Float>get(2));
        Log.d(TAG, "functionTest(): luaReturnValues.<Integer>get(3) = " + luaReturnValues.<Integer>get(3));
        Log.d(TAG, "functionTest(): luaReturnValues.<Boolean>get(4) = " + luaReturnValues.<Boolean>get(4));

//        Log.w(TAG, "functionTest(): luaReturnValues.<String>get(5) = " + luaReturnValues.<String>get(5));
//        Log.w(TAG, "functionTest(): luaReturnValues.<String>get(2) = " + luaReturnValues.<String>get(2));
//        Log.w(TAG, "functionTest(): luaReturnValues.<Number>get(0) = " + luaReturnValues.<Number>get(0));
//        Log.w(TAG, "functionTest(): luaReturnValues.<Boolean>get(0) = " + luaReturnValues.<Boolean>get(0));

        Log.d(TAG, "functionTest(): luaReturnValues.getString(0) = " + luaReturnValues.getString(0));
        Log.d(TAG, "functionTest(): luaReturnValues.getNumber(1) = " + luaReturnValues.getNumber(1));
        Log.d(TAG, "functionTest(): luaReturnValues.getNumber(2) = " + luaReturnValues.getNumber(2));
        Log.d(TAG, "functionTest(): luaReturnValues.getNumber(3) = " + luaReturnValues.getNumber(3));
        Log.d(TAG, "functionTest(): luaReturnValues.getBoolean(4) = " + luaReturnValues.getBoolean(4));

        Log.w(TAG, "functionTest(): luaReturnValues.getString(4) = " + luaReturnValues.getString(4));
        Log.w(TAG, "functionTest(): luaReturnValues.getNumber(0) = " + luaReturnValues.getNumber(0));
        Log.w(TAG, "functionTest(): luaReturnValues.getBoolean(1) = " + luaReturnValues.getBoolean(1));

        Log.d(TAG, "functionTest(): luaReturnValues.popString() = " + luaReturnValues.popString());
        Log.d(TAG, "functionTest(): luaReturnValues.popNumber() = " + luaReturnValues.popNumber());
        Log.d(TAG, "functionTest(): luaReturnValues.popNumber() = " + luaReturnValues.popNumber());
        Log.d(TAG, "functionTest(): luaReturnValues.popNumber() = " + luaReturnValues.popNumber());
        Log.d(TAG, "functionTest(): luaReturnValues.popBoolean() = " + luaReturnValues.popBoolean());

        Log.w(TAG, "functionTest(): luaReturnValues.popString() = " + luaReturnValues.popString());
        Log.w(TAG, "functionTest(): luaReturnValues.popNumber() = " + luaReturnValues.popNumber());
        Log.w(TAG, "functionTest(): luaReturnValues.popBoolean() = " + luaReturnValues.popBoolean());
    }

    interface LuaBasicTypes {
        int BOOLEAN = 1;
        int NUMBER = 2;
        int STRING = 3;
    }
}
