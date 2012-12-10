#include <jni.h>
#include "gamelogic.h"

bool isEmpty(int c,int r,int** board){

             if(board[c][r] == 2)	//val 2 = empty since 0 is player 1
             {
			 return true;
				}
             else
             {
			 return false;}
};
