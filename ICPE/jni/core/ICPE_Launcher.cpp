#include <jni.h>

#include "ICPE.h"

extern "C"
{
	JNIEXPORT jint JNI_OnLoad(JavaVM*vm,void*v)
	{
		ICPE::launch(vm,v);
		return JNI_VERSION_1_6;
	}
}
