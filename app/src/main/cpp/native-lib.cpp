#include <jni.h>
#include <string>
#include <stdlib.h>
#include <android/log.h>


#define TAG "myDemo-jni" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型


extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_jin_as_1ndk_1demo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    env->NewStringUTF("");
//    (*ENV).
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jin_as_1ndk_1demo_MainActivity_updateNameFromC(JNIEnv *env, jobject instance) {

    // TODO

    jclass jclass1 = env->GetObjectClass(instance);
    jfieldID jfieldID1 = env->GetFieldID(jclass1, "name", "Ljava/lang/String;");
    jstring result = (jstring)env->GetObjectField(instance,jfieldID1);
    printf("%#x\n", result);
    char* str = (char*)env->GetStringUTFChars(result, NULL);
    char text[20] = "success";
    char* finalresult = strcat(str, text);

    return env->NewStringUTF(finalresult);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jin_as_1ndk_1demo_MainActivity_getMethodFromJNI(JNIEnv *env, jobject instance) {

    // TODO

    jclass jclass1 = env->GetObjectClass(instance);
    jmethodID jmethodID1 = env->GetMethodID(jclass1, "getName", "()Ljava/lang/String;");
    jstring  result = (jstring)env->CallObjectMethod(instance, jmethodID1);
    char* str = (char*)env->GetStringUTFChars(result, NULL);
    char text[10] = "success";
    char* returnValue = strcat(str, text);

    return env->NewStringUTF(returnValue);
}

int comparator(const void* __lhs, const void* __rhs) {
    return *(int*)__lhs - *(int*)__rhs;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_jin_as_1ndk_1demo_MainActivity_getArray(JNIEnv *env, jobject instance,
                                                         jintArray arrays_) {
    jint *arrays = env->GetIntArrayElements(arrays_, NULL);
    int _len = env->GetArrayLength(arrays_);
    qsort(arrays, _len, sizeof(int), comparator);


    // TODO

    env->ReleaseIntArrayElements(arrays_, arrays, 0);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_jin_as_1ndk_1demo_MainActivity_getLocalReference(JNIEnv *env, jobject instance) {

    for (int i = 0; i < 100; i++) {
        jclass  jclass1 = env->FindClass("java/util/Date");
        jobject jobject1 = env->NewObject(jclass1, env->GetMethodID(jclass1, "<init>", "()V"));

        env->DeleteLocalRef(jobject1);
    }
    // TODO

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_jin_as_1ndk_1demo_MainActivity_exception(JNIEnv *env, jobject instance) {

    jclass jclass1 = env->GetObjectClass(instance);
    jfieldID jfieldID1 = env->GetFieldID(jclass1, "name2", "Ljava/lang/String;");

    jthrowable jthrowable1 = env->ExceptionOccurred();
    if (jthrowable1 != NULL) {
        env->ExceptionClear();
        jfieldID1 = env->GetFieldID(jclass1, "name", "Ljava/lang/String;");
    }
    jstring jstring1 = (jstring)env->GetObjectField(instance, jfieldID1);
    char* str = (char*)env->GetStringUTFChars(jstring1, NULL);

    if(strcmp(str, "www") != 0) {
        jclass newthrow = env->FindClass("java/lang/IllegalArgumentException");
        env->ThrowNew(newthrow, "非法参数");
    }
    // TODO

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_jin_as_1ndk_1demo_MainActivity_cache(JNIEnv *env, jobject instance) {

    jclass jclass1 = env->GetObjectClass(instance);

    static jfieldID jfieldID1 = NULL;
    if (jfieldID1 == NULL) {
        jfieldID1 = env->GetFieldID(jclass1, "name", "Ljava/lang/String;");
        LOGD("----------------------getfield-----------------------");
    }

    // TODO

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_jin_as_1ndk_1demo_MainActivity_init(JNIEnv *env, jclass type) {
    static jfieldID jfieldID1 = NULL;
    if (jfieldID1 == NULL) {
        jfieldID1 = env->GetFieldID(type, "name", "Ljava/lang/String;");
        LOGD("----------------------getfield   init -----------------------");
    }
    // TODO

}