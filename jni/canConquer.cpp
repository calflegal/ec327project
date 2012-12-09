#include <jni.h>

//put functions here

boolean * isValid(){
	return "it worked!";
}

extern "C"{

	 Java_com_ec327cassio_reversi_MainActivity_isValid()
	{
		return env->
	}
}


bool canConquerUp(c, r, p){
    if (r > 1) {
	 bool enclosing = false;
     // impossible enclose upwards if row is less than 2
     if (r > 1) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c][r - 1] == op(p)) {

                     int value = getFirstPositionDifferentThan(
                                     op(player), c, r - 1, /*Direction.X.NONE*/0,
                                     -1/*Direction.Y.UP*/);
                     // only encloses if the first different than opponent is an own
                     // chip
                     enclosing = value == player;
             }
     }
     return enclosing;
}
