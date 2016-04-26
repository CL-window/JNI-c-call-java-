package com.example.root.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import java.text.SimpleDateFormat;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Log.e("slack",getDataFromCCode());

        //JniData.getTime();

        putDataToJavaCode();

        putDataToJavaCodeWithParams("slack");

        putDataToJavaCodeWithParamsAndReturn("slacking");

    }

    static{
        System.loadLibrary("jnidemo");
    }
    // java 调用 c
    public native String getDataFromCCode();

    //  c 调用 java  这里是先java调用c（可以直接c函数里调用javaset ,但是需要c代码先跑起来）,再c调用java
    public native void putDataToJavaCode();
    // c 调用 java 有参数，无返回值
    public native void putDataToJavaCodeWithParams(String data);
    //c 调用 java 有参数，无返回值 get set 方法改变java里的值
    public native void putDataToJavaCodeWithParamsAndReturn(String data);




}
