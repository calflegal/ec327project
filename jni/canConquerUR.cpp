#include <jni.h>
#include "gamelogic.h"



bool canConquerUR(int c, int r,int p, int** board){
	 bool check = false;
     // impossible to conquer if space is less than 2
     if (c < 6 && r > 1 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c+1][r-1] == op(p)) {

                     int value = checkLine(op(p), (c+1), (r-1) ,1, -1, board);
                     check = value ==p;

             }
     }
     return check;
};


