#include <jni.h>
#include "gamelogic.h"


bool canConquerDown(int c, int r,int p, int** board){
	 bool check = false;
     // impossible to conquer if space is less than 2
     if (r <6 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c][r+1] == op(p)) {

                     int value = checkLine(op(p), c, (r+1) , 0, 1, board);
                     check = value ==p;

             }
     }
     return check;
};
