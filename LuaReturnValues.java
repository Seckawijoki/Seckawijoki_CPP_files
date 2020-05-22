package org.appplay.lua;
import android.util.Log;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
/**
 * only instantiated from c++
 * Created by Seckawijoki on 2019/9/26 at 16:40 under Windows-10 Professional.
 */
public class LuaReturnValues {
    private static final String TAG = "LuaReturnValues";
    private List<Object> mObjectList = new ArrayList<>();
    private int mCurrentBooleanIndex = 0;
    private int mCurrentNumberIndex = 0;
    private int mCurrentStringIndex = 0;
    private Class[] mReturnTypes;
    /**
     * c++ used
     */
    public LuaReturnValues(){
        Log.i(TAG, "LuaReturnValues(): ");
    }

    private boolean outside(int index){
        return index < 0 || index >= mObjectList.size();
    }

    public boolean popBoolean(){
        for ( int i = mCurrentBooleanIndex ; i < mObjectList.size() ; ++i ) {
            if (mObjectList.get(i) instanceof Boolean){
                mCurrentBooleanIndex = i + 1;
                return (Boolean) mObjectList.get(i);
            }
        }
        Log.w(TAG, "popBoolean(): no more boolean to get");
        return false;
    }

    public double popNumber(){
        for ( int i = mCurrentNumberIndex ; i < mObjectList.size() ; ++i ){
          if (mObjectList.get(i) instanceof Double){
              mCurrentNumberIndex = i + 1;
              return (double) mObjectList.get(i);
          }
        }
        Log.w(TAG, "popNumber(): no more number to get");
        return 0;
    }

    public String popString(){
        for ( int i = mCurrentStringIndex ; i < mObjectList.size() ; ++i ){
            if (mObjectList.get(i) instanceof String){
                mCurrentStringIndex = i + 1;
                return (String) mObjectList.get(i);
            }
        }
        Log.w(TAG, "popString(): no more String to get");
        return "";
    }

    public Object getObject(int index){
        if (outside(index)){
            return null;
        }
        return mObjectList.get(index);
    }

    @Deprecated
    public <T> T get(int index){
        Object object = getObject(index);
        try {
            return object != null ? (T) object : null;
        } catch (ClassCastException e) {
            return null;
        }
    }

    public boolean getBoolean(int index){
        if (outside(index)){
            Log.w(TAG, "getBoolean(): out of bound");
            return false;
        }
        Object object = mObjectList.get(index);
        if ( object instanceof Boolean ) {
            return (Boolean) object;
        }
        else {
            Log.w(TAG, "getBoolean(): current index is not a boolean: " + index);
            return false;
        }
    }

    public double getNumber(int index){
        if (outside(index)){
            Log.w(TAG, "getNumber(): out of bound");
            return 0;
        }
        Object object = mObjectList.get(index);
        if ( object instanceof Double ) {
            return (Double) object;
        } else {
            Log.w(TAG, "getNumber(): current index is not a number: " + index);
            return 0;
        }
    }

    public String getString(int index){
        if (index < 0 || index >= mObjectList.size()){
            Log.w(TAG, "getString(): out of bound");
            return "";
        }
        Object object = mObjectList.get(index);
        if (object instanceof String){
            return (String) object;
        } else {
            Log.w(TAG, "getString(): current index is not a String: " + index);
            return object.toString();
        }
    }

    public void setReturnTypes(Class[] returnTypes) {
        mReturnTypes = returnTypes;
    }

    private void addBoolean(boolean z){
        Log.d(TAG, "addBoolean(): z = " + z);
        mObjectList.add(z);
    }

    private void addNumber(double db){
        Log.d(TAG, "addNumber(): db = " + db);
        mObjectList.add(db);
    }

    private void addString(String s){
        Log.d(TAG, "addString(): s = " + s);
        mObjectList.add(s);
    }

    private void addBooleanArray(boolean[] zs){
        Log.d(TAG, "addBooleanArray(): zs = " + Arrays.toString(zs));
        mObjectList.add(zs);
    }

    private void addNumberArray(double[] dbs){
        Log.d(TAG, "addNumberArray(): dbs = " + Arrays.toString(dbs));
        mObjectList.add(dbs);
    }

    private void addStringArray(String[] strings){
        Log.d(TAG, "addStringArray(): strings = " + Arrays.toString(strings));
        mObjectList.add(strings);
    }

    @Override
    public String toString() {
        return mObjectList.toString();
    }
}
