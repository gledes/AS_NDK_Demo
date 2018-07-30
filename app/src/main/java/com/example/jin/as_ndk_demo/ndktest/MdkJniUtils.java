package com.example.jin.as_ndk_demo.ndktest;

/**
 * Created by jin on 2018/7/30.
 */

public class MdkJniUtils {


    static {
        System.loadLibrary("MyTestJniLib");
    }


    public native String getCLanguageString();
}
