#include <jni.h>
#include "gamelogic.h"

//put functions here
/*
extern "C"{

 Java_com_ec327cassio_reversi_MainActivity_isValid()
	{
		return env->
	}

}
*/

bool isEmpty(int board[8][8]){
             if(board[r][c] == 2)	//val 2 = empty
             { return true }
             else
             { return false}
          }
