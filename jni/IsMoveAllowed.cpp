#include <jni.h>
#include "gamelogic.h"

using namespace std;

//put functions here
//extern "C"{
//Jboolean Java_com_ec327cassio_reversi_MainActivity_isValid(JNIEnv * env, jobject obj, jint c, jint r, int* board, int p ))

bool isValid( int c, int r, int** board, int p) {
             bool canPut;

             canPut = isEmpty(c,r,board) && ( (canConquerUp(c, r, p, board))	||
            		 	 	 	 	 	 	  (canConquerDown(c, r, p, board))	||
            		 	 	 	 	 	 	  (canConquerLeft(c, r, p, board))	||
            		 	 	 	 	 	 	  (canConquerRight(c, r, p, board)) ||
            		 	 	 	 	 	 	  (canConquerDL(c, r, p, board))	||
            		 	 	 	 	 	 	  (canConquerDR(c, r, p, board))	||
            		 	 	 	 	 	 	  (canConquerUL(c, r, p, board)) 	||
            		 	 	 	 	 	 	  (canConquerUR(c, r, p, board))    );
            		 	 	 	 	 	 

             return canPut;

        }





 



