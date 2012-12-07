#include <jni.h>
#include <string.h>
//put functions here

const char * CPPgetString(){
	return "it worked!";
}

extern "C"{

	jstring
	Java_com_ec327cassio_reversi_MainActivity_getString(JNIEnv * env, jobject obj)
	{

		return env->NewStringUTF(CPPgetString());
	}
}
