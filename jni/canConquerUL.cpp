#include <jni.h>
#include "gamelogic.h"


bool canConquerUL(int c, int r,int p, int** board){
	 bool enclosing = false;
     // impossible to conquer if space is less than 2
     if (c > 1 && r > 1 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c-1][r-1] == op(p)) {

                     int value = checkLine(op(p), (c-1), (r-1) ,-1, -1, board);
                     enclosing = value ==p;

             }
     }
     return enclosing;
}


