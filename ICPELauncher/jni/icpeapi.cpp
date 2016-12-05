#include <string.h>
#include <jni.h>

static JNIEnv *GetEnv(JavaVM*g_JavaVM)
{
	int status;
    JNIEnv *envnow = NULL;
    status = g_JavaVM->GetEnv((void **)&envnow, JNI_VERSION_1_4);
    if(status < 0)
    {
        status = g_JavaVM->AttachCurrentThread(&envnow, NULL);
        if(status < 0)
            return NULL;
    }
    return envnow;
}

extern "C"
{
	JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void*)
	{
		jclass systemClass=GetEnv(vm)->FindClass("java/lang/System");
		jmethodID mid = GetEnv(vm)->GetStaticMethodID(systemClass, "load", "(Ljava/lang/String;)[V");
		GetEnv(vm)->CallStaticVoidMethod(systemClass,mid,GetEnv(vm)->NewStringUTF("/data/data/com.mojang.minecraftpe/lib/libminecraftpe.so"));
		return JNI_VERSION_1_6;
	}
}
