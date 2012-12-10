#include <jni.h>
#include "gamelogic.h"
//put functions here


bool C_isValid( int x, int y, int** board, int player) {
             bool Valid;

             Valid = isEmpty(x,y,board) && ( (canConquerUp(x, y, player, board))	||
            		 	 	 	 	 	 	  (canConquerDown(x, y, player, board))	||
            		 	 	 	 	 	 	  (canConquerLeft(x, y, player, board))	||
            		 	 	 	 	 	 	  (canConquerRight(x, y, player, board)) ||
            		 	 	 	 	 	 	  (canConquerDL(x, y, player, board))	||
            		 	 	 	 	 	 	  (canConquerDR(x, y, player, board))	||
            		 	 	 	 	 	 	  (canConquerUL(x, y, player, board)) 	||
            		 	 	 	 	 	 	  (canConquerUR(x, y, player, board))    );


             return Valid;

        }

//=======================================================================================
bool isEmpty(int x,int y,int** board){

             if(board[x][y] == 2)	//val 2 = empty
             { 	 return true;				}
             else
             { 	 return false;}
}
//=======================================================================================
int op(int player){
	if(player==1)
	{		return 0;	}
		else if (player == 0)
	{		return 1;	}

}

//=======================================================================================
int checkLine(int player, int initialColumn,
 int initialRow, int directionX, int directionY, int** board) {

// stores the value of the first position with a value different than
 // the player value
 int cline = player;
 bool resolved = false;

  int x = initialColumn;
    int y = initialRow;
   while (!resolved) {
 x += directionX;
    y += directionY;
   // if we are inside the bounds of the board game
      if (x >= 0 && x < 8 && y >= 0 && y < 8) {

  if (board[x][y] != player) {
        resolved = true;
          cline = board[x][y];
   }
 } else {
     // out of bounds means resolved with no different position
  resolved = true;
  }
  }

 return cline;
  }
//=======================================================================================

bool canConquerDL(int x, int y,int player, int** board){
	 bool check = false;
     // impossible to conquer if space is less than 2
     if (x > 1 && y < 6 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[x-1][y+1] == op(player)) {

                     int value = checkLine(op(player), (x-1), (y+1) , -1, +1, board);

                     check = value ==player;

             }
     }
     return check;
}

//=======================================================================================

bool canConquerDown(int x, int y,int player, int** board){
	 bool check = false;
     // impossible to conquer if space is less than 2
     if (y <6 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[x][y+1] == op(player)) {

                     int value = checkLine(op(player), x, (y+1) , 0, 1, board);
                     check = value ==player;

             }
     }
     return check;
}


//=======================================================================================
bool canConquerDR(int x, int y,int player, int** board){
	 bool check = false;
     // impossible to conquer if space is less than 2
     if (x < 6 && y < 6 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[x+1][y+1] == op(player)) {

                     int value = checkLine(op(player), (x+1), (y+1) ,1, 1, board);
                     check = value ==player;

             }
     }
     return check;
}




//=======================================================================================

bool canConquerLeft(int x, int y,int player, int** board){
	 bool check = false;
     // impossible to conquer if space is less than 2
     if (x > 1 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[x-1][y] == op(player)) {

                     int value = checkLine(op(player), (x-1), y ,-1,0, board);
                     check = value == player;

             }
     }
     return check;
}

//=======================================================================================

bool canConquerRight(int x, int y,int player, int** board){
	 bool check = false;
     // impossible to conquer if space is less than 2
     if (x < 6 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[x+1][y] == op(player)) {

                     int value = checkLine(op(player), (x+1), y ,1,0, board);
                     check = value == player;

             }
     }
     return check;
}


//=======================================================================================
bool canConquerUL(int x, int y,int player, int** board){
	 bool check = false;
     // impossible to conquer if space is less than 2
     if (x > 1 && y > 1 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[x-1][y-1] == op(player)) {

                     int value = checkLine(op(player), (x-1), (y-1) ,-1, -1, board);
                     check = value ==player;

             }
     }
     return check;
}



//=======================================================================================

bool canConquerUp(int x, int y,int player, int** board){
	 bool check = false;
     // impossible to conquer if space is less than 2
     if (y > 1) {

             // impossible to enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[x][y-1] == op(player)) {

                     int value = checkLine( op(player), x, (y -1) ,0,-1, board);
                     check = value;

             }
     }
     return check;
}

//=======================================================================================
bool canConquerUR(int x, int y,int player, int** board){
	 bool check = false;
     // impossible to conquer if space is less than 2
     if (x < 6 && y > 1 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[x+1][y-1] == op(player)) {

                     int value = checkLine(op(player), (x+1), (y-1) ,1, -1, board);
                     check = value ==player;

             }
     }
     return check;
}



//=======================================================================================


int Conquer(int x, int y, int directionX, int directionY, int** board,int player)
{

         //       int x = x;
            //    int y = y;

                bool ownChip = false;


                //conquer until an own chip is found
                while ( !ownChip ) {
                        //advancing in the given direction
                        x += directionX;
                        y += directionY;

                        //if is not an own chip
                        if (board[x][y] != player) {
                                board[x][y] = player;
                        } else {
                                ownChip = true;
                        }
                }
        }
//=======================================================================================

void fixBoard(int x, int y,  int** board, int player)
{
if(canConquerUp(  x,  y, player, board ))
{	Conquer( x,  y, 0, -1,  board, player);	}

if(canConquerDown(  x,  y, player, board ))
{	Conquer( x,  y, 0, 1,  board, player);	}

if(canConquerLeft(  x,  y, player, board ))
{	Conquer( x,  y, -1, 0,  board, player);	}

if(canConquerRight(  x,  y, player, board ))
{	Conquer( x,  y, 1, 0,  board, player);	}

if(canConquerDL(  x,  y, player, board ))
{	Conquer( x,  y, -1, 1,  board, player);	}

if(canConquerDR(  x,  y, player, board ))
{	Conquer( x,  y, 1, 1,  board, player);	}

if(canConquerUL(  x,  y, player, board ))
{	Conquer( x,  y, -1, -1,  board, player);	}

if(canConquerUR(  x,  y, player, board ))
{	Conquer( x,  y, 1, -1,  board, player);	}
}


//=======================================================================================
extern "C"{

//	jboolean Java_com_ec327cassio_reversi_MainActivity_getString(JNIEnv * env, jobject )
//	{
//		return env->NewStringUTF(CPPgetString());
//	}


	JNIEXPORT jboolean JNICALL
Java_com_ec327cassio_reversi_MainActivity_isValid(JNIEnv * env, jobject, jint x,
	jint y, jobjectArray board, jint player)
	{
		int len1 = 8;
		int **the_c_board;
		the_c_board = new int*[len1];
		//populate
		for (int i =0; i < 8; i++) {
			jintArray row = (jintArray)env->GetObjectArrayElement(board,i);
			jint *element = env->GetIntArrayElements(row,0);
			//allocate the sub-array for the row
			the_c_board[i] = new int[len1];
			for (int j=0; j<8; j++) {
				the_c_board[i][j] = element[j];
			}
		}
		bool result = C_isValid((int)x,(int) y,the_c_board,(int)player);


		//properly delete the array before returning bool
		for (int k=0; k<8; k++) {
			delete [] the_c_board[k];
		}
		delete [] the_c_board;
		return (jboolean) result;

	}

	JNIEXPORT void JNICALL
    Java_com_ec327cassio_reversi_MainActivity_FixBoard(JNIEnv * env, jobject, jint x,
	jint y, jint board[8][8], jint player)
	{


	}


}
/*android.mk
 *
 * LOCAL_SRC_FILES += isValid.cpp
LOCAL_SRC_FILES += ConquerDirection.cpp
LOCAL_SRC_FILES += checkLine.cpp
LOCAL_SRC_FILES += op.cpp
LOCAL_SRC_FILES += isEmpty.cpp
LOCAL_SRC_FILES += Conquer.cpp
LOCAL_SRC_FILES += canConquerUp.cpp
LOCAL_SRC_FILES += canConquerDown.cpp
LOCAL_SRC_FILES += canConquerLeft.cpp
LOCAL_SRC_FILES += canConquerRight.cpp
LOCAL_SRC_FILES += canConquerDL.cpp
LOCAL_SRC_FILES += canConquerDR.cpp
LOCAL_SRC_FILES += canConquerUL.cpp
LOCAL_SRC_FILES += canConquerUR.cpp
 *
 */


