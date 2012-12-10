#include <jni.h>
#include "gamelogic.h"


        bool canConquerLeft(int c, int r,int p, int** board){
        	 bool check = false;
             // impossible to conquer if space is less than 2
             if (c > 1 ) {

                     // impossible enclose upwards if adjacent upwards chip is not
                     // opponent
                     if (board[c-1][r] == op(p)) {

                             int value = checkLine(op(p), (c-1), r ,-1,0, board);
                             check = value == p;

                     }
             }
             return check;
        };
