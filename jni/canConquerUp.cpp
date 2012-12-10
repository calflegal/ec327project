#include <jni.h>
#include "gamelogic.h"



bool canConquerUp(int c, int r,int p, int** board){
	 bool enclosing = false;
     // impossible to conquer if space is less than 2
     if (r > 1) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c][r-1] == op(p)) {

                     int value = checkLine( op(p), c, (r -1) ,0,-1, board);
                     enclosing = value;

             }
     }
     return enclosing;
}
