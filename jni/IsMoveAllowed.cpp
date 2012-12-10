#include <jni.h>
#include "gamelogic.h"

//put functions here


extern "C"{


Jboolean Java_com_ec327cassio_reversi_MainActivity_isValid(JNIEnv * env, jobject obj, jint c, jint r, jint board[][], jint p ))
		{
//bool isValid( int c, int r, int board[8][8], int p) {

             bool canPut;


             canPut = isEmpty(c, r) && ( (canConquerUP(c, r, p)) ||
            		 	 	 	 	 	 (canConquerDOWN(c, r, p))

             );


             return canPut;

        }


}



/////////////


//-----------------


