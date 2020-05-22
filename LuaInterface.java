package org.appplay.lua;

final class LuaInterface {
    private LuaInterface(){throw new RuntimeException();}
    static native long obtain();
    static native void debug(long pNativeBuilder, boolean debug);
    static native boolean getTable(long pNativeBuilder, final String szTableName);
    static native boolean getFunction(long pNativeBuilder, final String szFunctionName);
    static native boolean getSelfFunction(long pNativeBuilder, final String szFunctionName);
    static native boolean pushBoolean(long pNativeBuilder, final boolean b);
    static native boolean pushNumber(long pNativeBuilder, final double db);
    static native boolean pushString(long pNativeBuilder, final String str);
//    static native boolean pushBooleanArray(long pNativeBuilder, final boolean[] booleans);
//    static native boolean pushNumberArray(long pNativeBuilder, final double[] doubles);
//    static native boolean pushStringArray(long pNativeBuilder, final String[] strings);
    static native void setReturnCount(long pNativeBuilder, final int count);
    static native boolean setReturnTypes(long pNativeBuilder, final String format);
    static native LuaReturnValues call(long pNativeBuilder);
}
