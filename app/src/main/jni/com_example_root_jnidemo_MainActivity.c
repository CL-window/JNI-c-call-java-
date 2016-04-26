//#include "com_example_root_jnidemo_MainActivity.h"
//#include "android/log.h"
//
//void __func__useStaticMethod(JNIEnv *pInterface, jobject pVoid);
//void __func__useStaticMethodc__useMethod(JNIEnv *pInterface, jobject pVoid);
//void __func__userMethodWithParams(JNIEnv *pInterface, jobject pVoid, jstring data);
//void __func__userMethodWithParamsAndReturn(JNIEnv *pInterface, jobject pVoid, jstring data);
//
//JNIEXPORT jstring JNICALL
//                  Java_com_example_root_jnidemo_MainActivity_getDataFromCCode(JNIEnv *env, jobject instance) {
//
//    // 日志输出
//    __android_log_write(ANDROID_LOG_INFO,"slack","This is a Test...");
//    //返回 activity
//    return (*env)->NewStringUTF(env,"I'm comes from to Native Function!");
//
//}
//
///* 在c代码里面调用java代码里面的方法
// * http://www.cnblogs.com/likwo/archive/2012/05/21/2512400.html
// *
// * JNIEnv类型代表Java环境。通过这个JNIEnv*指针，就可以对Java端的代码进行操作。
// * 如，创建Java类得对象，调用Java对象的方法，获取Java对象的属性等。
// * JNIEnv的指针会被JNI传送到本地方法的实现函数中来对Java端的代码进行操作
// *
// * jobject instance 代表当前类对象，即调用 native 方法的那个类
// *
// *
// * */
//void JNICALL
//Java_com_example_root_jnidemo_MainActivity_putDataToJavaCode(JNIEnv *env, jobject instance) {
//
//    __func__useStaticMethod(env, instance);
//
//    __func__useMethod(env,instance);
//
//}
//
//
///*
// * Class:     com_example_root_jnidemo_MainActivity
// * Method:    putDataToJavaCodeWithParams
// * Signature: (Ljava/lang/String;)V
// */
//JNIEXPORT  void JNICALL Java_com_example_root_jnidemo_MainActivity_putDataToJavaCodeWithParams
//        (JNIEnv * env, jobject instance, jstring data){
//
//    __func__userMethodWithParams(env,instance,data);
//
//}
//
//
//JNIEXPORT void JNICALL Java_com_example_root_jnidemo_MainActivity_putDataToJavaCodeWithParamsAndReturn
//        (JNIEnv * env, jobject instance, jstring data){
//
//    __func__userMethodWithParamsAndReturn(env,instance,data);
//
//}
//
//
//// 调用java  无参数的static 无返回
//void __func__useStaticMethod(JNIEnv *env, jobject instance) {
//
//    // java 反射
//    //1  .找到java代码的 class文件
//    //    jclass      (*FindClass)(JNIEnv*, const char*);
//    __android_log_write(ANDROID_LOG_INFO,"slack","1 ...");
////    jclass native_clazz = (*env)->GetObjectClass(env,"com/example/root/jnidemo/JniData");
//    //static  methods
//    jclass native_clazz = (*env)->FindClass(env,"com/example/root/jnidemo/JniData");
//    __android_log_write(ANDROID_LOG_INFO,"slack","2 ...");
//    if(native_clazz == 0){
//        __android_log_write(ANDROID_LOG_ERROR,"slack","find class error ...");
//        return;
//    }
//    //2 .寻找class里面的方法
//    //   jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
////    jmethodID methodid = (*env)->GetMethodID(env,native_clazz,"getTime","()V");
//    //static  methods
//    // 最后一个参数  签名是对函数参数和返回值的描述   签名参照 .h 文件
//    jmethodID methodid = (*env)->GetStaticMethodID(env,native_clazz,"getStaticTime","()V");
//    __android_log_write(ANDROID_LOG_INFO,"slack","3 ...");
//    if(methodid == 0){
//        __android_log_write(ANDROID_LOG_ERROR,"slack"," find method error ...");
//        return;
//    }
//    __android_log_write(ANDROID_LOG_INFO,"slack","4 ...");
//    //3 .调用这个方法
//    //    void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
//    // calling static method void com.example.root.jnidemo.JniData.getTime() with CallVoidMethod
////    (*env)->CallVoidMethod(env,instance,methodid);
//    //JNI DETECTED ERROR IN APPLICATION: jclass has wrong type: com.example.root.jnidemo.MainActivity
//    //    void        (*CallStaticVoidMethod)(JNIEnv*, jclass, jmethodID, ...);
//    (*env)->CallStaticVoidMethod(env,native_clazz,methodid);
//    // 尽量让C要调用的Java方法在同一个类中
//    // C调用的Java方法不在一个类中
//    // jclass has wrong type: com.example.root.jnidemo.JniData
////    jobject dpobj= (*env)->AllocObject(env,native_clazz);
//
////    (*env)->CallStaticVoidMethod(env,dpobj,methodid);
//}
//
//// 调用java  无参数的非static 无返回 需要类似 java里的 new一个对象
//void __func__useMethod(JNIEnv *env, jobject instance) {
//
//    __android_log_write(ANDROID_LOG_INFO,"slack","1 ...");
//    //1  .找到java代码的 class文件  java 反射
//    //static  methods   FindClass 根据类名来查找一个类，完整类名
//    jclass native_clazz = (*env)->FindClass(env,"com/example/root/jnidemo/JniData");
//    __android_log_write(ANDROID_LOG_INFO,"slack","2 ...");
//    if(native_clazz == 0){
//        __android_log_write(ANDROID_LOG_ERROR,"slack","find class error ...");
//        return;
//    }
//    //2 .C中新建java对象 通过NewObject来创建对象
//    //默认构造函数，不传参数
//    jmethodID construction_id = (*env)->GetMethodID(env, native_clazz,"<init>", "()V");
//    jobject mJavaObject = (*env)->NewObject(env, native_clazz,construction_id);
//
//    //3 .寻找class里面的方法
//    //   jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
//    jmethodID methodid = (*env)->GetMethodID(env,native_clazz,"getTime","()V");
//
//    __android_log_write(ANDROID_LOG_INFO,"slack","3 ...");
//    if(methodid == 0){
//        __android_log_write(ANDROID_LOG_ERROR,"slack"," find method error ...");
//        return;
//    }
//    __android_log_write(ANDROID_LOG_INFO,"slack","4 ...");
//    //3 .调用这个方法 jobject 是新建出来的那个对象
//    //    void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
//    (*env)->CallVoidMethod(env,mJavaObject,methodid);
//
//
//}
//
///* java 调用 c 时传参数  关键是这里的参数的类型转换
// * c 调用 java 里有参数无返回值的非静态方法
// * 在java中由于是unicode编码，无论是英文字母还是汉字每个字符都是占用2个字节。但是在jni中的字符是utf-8编码，每个字符不是等长的
// * */
//void __func__userMethodWithParams(JNIEnv * env, jobject instance, jstring data) {
//    // jstring --> char *
//    // const char * GetStringUTFChars(JNIEnv *env, jstring string,jboolean *isCopy);
//    char * ch = (char*)((*env)->GetStringUTFChars(env,data,0));
//    __android_log_write(ANDROID_LOG_INFO,"slack",ch);
//
//    // c 调用 java 里有参数无返回值的非静态方法
//    __android_log_write(ANDROID_LOG_INFO,"slack","1 ...");
//    //1  .找到java代码的 class文件  java 反射
//    //static  methods   FindClass 根据类名来查找一个类，完整类名
//    jclass native_clazz = (*env)->FindClass(env,"com/example/root/jnidemo/JniData");
//    __android_log_write(ANDROID_LOG_INFO,"slack","2 ...");
//    if(native_clazz == 0){
//        __android_log_write(ANDROID_LOG_ERROR,"slack","find class error ...");
//        return;
//    }
//    //2 .C中新建java对象 通过NewObject来创建对象
//    //默认构造函数，不传参数
//    jmethodID construction_id = (*env)->GetMethodID(env, native_clazz,"<init>", "()V");
//    jobject mJavaObject = (*env)->NewObject(env, native_clazz,construction_id);
//
//    //3 .寻找class里面的方法
//    //   jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*); 有参数 参照 .h 文件
//    jmethodID methodid = (*env)->GetMethodID(env,native_clazz,"getTime","(Ljava/lang/String;)V");
//
//    __android_log_write(ANDROID_LOG_INFO,"slack","3 ...");
//    if(methodid == 0){
//        __android_log_write(ANDROID_LOG_ERROR,"slack"," find method error ...");
//        return;
//    }
//    __android_log_write(ANDROID_LOG_INFO,"slack","4 ...");
//
//    //  char * --> jstring  传java函数里的参数
//    // jstring NewStringUTF(JNIEnv *env, const char *bytes);
//    jstring  datas = (*env)->NewStringUTF(env,ch);
//
//    //4 .调用这个方法 jobject 是新建出来的那个对象
//    //    void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
//    (*env)->CallVoidMethod(env,mJavaObject,methodid,datas);
//
//}
//
///* java 调用 c 时传参数
// * c 调用 java 里有参数有返回值的非静态方法 即java端运算完成后返回给 c 端
// * 这里通过 GetIntField()  SetIntField（） 来实现
// * */
//void __func__userMethodWithParamsAndReturn(JNIEnv * env, jobject instance, jstring data) {
//
//    // jstring --> char *
//    // const char * GetStringUTFChars(JNIEnv *env, jstring string,jboolean *isCopy);
//    char * ch = (char*)((*env)->GetStringUTFChars(env,data,0));
//    __android_log_write(ANDROID_LOG_INFO,"slack",ch);
//
//    // c 调用 java 里有参数有返回值的非静态方法
//    __android_log_write(ANDROID_LOG_INFO,"slack","1 ...");
//    //1  .找到java代码的 class文件  java 反射
//    //static  methods   FindClass 根据类名来查找一个类，完整类名
//    jclass native_clazz = (*env)->FindClass(env,"com/example/root/jnidemo/JniData");
//
//    __android_log_write(ANDROID_LOG_INFO,"slack","2 ...");
//    if(native_clazz == 0){
//        __android_log_write(ANDROID_LOG_ERROR,"slack","find class error ...");
//        return;
//    }
//
//     // .C中新建java对象 通过NewObject来创建对象
//    //默认构造函数，不传参数
//    jmethodID construction_id = (*env)->GetMethodID(env, native_clazz,"<init>", "()V");
//    jobject mJavaObject = (*env)->NewObject(env, native_clazz,construction_id);
//    __android_log_write(ANDROID_LOG_INFO,"slack","3 ...");
//
//    // .得到jfieldID
//    // jfieldID GetFieldID(JNIEnv *env, jclass clazz,const char *name, const char *sig);
//    jfieldID fieldID_param = (*env)->GetFieldID(env,native_clazz,"param","Ljava/lang/String;"); //获得属性句柄
//    if(fieldID_param == 0){
//        __android_log_write(ANDROID_LOG_ERROR,"slack","find jfieldID error ...");
//        return;
//    }
//    __android_log_write(ANDROID_LOG_INFO,"slack","4...");
//
//    // .得到param
//    // NativeType Get<type>Field(JNIEnv *env, jobject obj,jfieldID fieldID);
//    jstring  param= (jstring )(*env)->GetObjectField(env,mJavaObject,fieldID_param);
//    __android_log_write(ANDROID_LOG_INFO,"slack", (char*)((*env)->GetStringUTFChars(env,param,0)));
//    // .修改param属性的值
//    char * c_param = "slack come from Native" ;
//    param = (*env)->NewStringUTF(env,c_param);//构造一个jstring对象
//    // void Set<type>Field(JNIEnv *env, jobject obj, jfieldID fieldID,NativeType value);
//    (*env)->SetObjectField(env , mJavaObject, fieldID_param, param); // 设置该字段的值
//
//
//    param= (jstring )(*env)->GetObjectField(env,mJavaObject,fieldID_param);
//    __android_log_write(ANDROID_LOG_INFO,"slack", (char*)((*env)->GetStringUTFChars(env,param,0)));
//
//}