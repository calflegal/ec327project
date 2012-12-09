#include <jni.h>
#include "gamelogic.h"


bool canConquerUp(c, r, p){
	 bool enclosing = false;
     // impossible to conquer down if space is less than 2
     if (r < 6) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c][r + 1] == op(p)) {

                     int value = checkLine(
                                     op(player), c, r + 1, /*Direction.X.NONE*/0,
                                     +1/*Direction.Y.UP*/);
                     // only encloses if the first different than opponent is an own
                     // chip
                     enclosing = value == player;
             }
     }
     return enclosing;
}
