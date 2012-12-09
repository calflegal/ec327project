#include <jni.h>
#include <string.h>
//put functions here

const char * CPPgetString(){
	return "it worked!";
}
//include something for if player is blocked.
extern "C"{

	jboolean Java_com_ec327cassio_reversi_MainActivity_getString(JNIEnv * env, jobject board[8][8])
	{
		return env->NewStringUTF(CPPgetString());
	}
}






