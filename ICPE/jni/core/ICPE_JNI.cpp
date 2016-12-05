#include <jni.h>

#include "ICPE.h"

extern "C"
{
	JNIEXPORT jint JNI_OnLoad(JavaVM*vm,void*v)
	{
		return ICPE::onJNI_Loaded(vm,v);
	}
}
