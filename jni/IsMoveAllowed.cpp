//#include <jni.h>
#include "gamelogic.h"
#include <iostream>
using namespace std;

//put functions here
//extern "C"{
//Jboolean Java_com_ec327cassio_reversi_MainActivity_isValid(JNIEnv * env, jobject obj, jint c, jint r, int* board, int p ))

bool isValid( int c, int r, int** board, int p) {
		cout << board[5][3] << endl;
             bool canPut;
			bool is;
			bool cu;

             canPut = isEmpty(c,r,board) && ( (canConquerUp(c, r, p, board)));
            		 	 	 	 	 	 

             return canPut;

        }




 



