package com.example.root.jnidemo;

import android.util.Log;

import java.text.SimpleDateFormat;

/**
 * Created by root on 16-4-25.
 */
public class JniData {

    // 非static c调用时会新建一个对象，无所谓 权限修饰符
    private String param = "slack form java";

//    private String getTime(){
//        return new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(System.currentTimeMillis());
//    }

    // static 必须是 public
    public static void getStaticTime(){
        Log.i("slack", new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(System.currentTimeMillis()) );
    }
    // 非static c调用时会新建一个对象，无所谓 权限修饰符
    public void getTime(){
        Log.i("slack", new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(System.currentTimeMillis()) );
    }
    // 非static c调用时会新建一个对象，无所谓 权限修饰符
    private void getTime(String data){
        Log.i("slack", data+"..." );
    }


}
