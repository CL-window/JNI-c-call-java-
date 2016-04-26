http://blog.csdn.net/i_do_can/article/details/51250371
生成 *.h 文件
root@chenling-VirtualBox:/home/chenling/java/androidstudio/JNIDemo/app/src/main# cd java/
root@chenling-VirtualBox:/home/chenling/java/androidstudio/JNIDemo/app/src/main/java# javah -d ../jni com.example.root.jnidemo.MainActivity
root@chenling-VirtualBox:/home/chenling/java/androidstudio/JNIDemo/app/src/main/java#

*.h + *.c --> *.so
不配置Android.mk 文件，生成的so文件 app/build/intermediates/ndk/debug/lib