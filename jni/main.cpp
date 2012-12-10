#include <jni.h>
#include "gamelogic.h"
//put functions here

extern "C"{

	jboolean Java_com_ec327cassio_reversi_MainActivity_getString(JNIEnv * env, jobject board[8][8])
	{
		return env->NewStringUTF(CPPgetString());
	}


//	JNIEXPORT jboolean JNICALL
	jboolean Java_com_ec327cassio_reversi_MainActivity_isValid(JNIEnv * env, jobject, jint x,
	jint y, jint ** board, jint player)
	{
		return (bool) canPut;

	}

//	JNIEXPORT void JNICALL
	jvoid Java_com_ec327cassio_reversi_MainActivity_FixBoard(JNIEnv * env, jobject, jint c,
	jint r, jint ** board, jint p)
	{
		return env -> board;

	}


}
//=======================================================================================
const char * CPPgetString(){
	return "it worked!";
}
//=======================================================================================
bool isValid( int c, int r, int** board, int p) {
             bool canPut;

             canPut = isEmpty(c,r,board) && ( (canConquerUp(c, r, p, board))	||
            		 	 	 	 	 	 	  (canConquerDown(c, r, p, board))	||
            		 	 	 	 	 	 	  (canConquerLeft(c, r, p, board))	||
            		 	 	 	 	 	 	  (canConquerRight(c, r, p, board)) ||
            		 	 	 	 	 	 	  (canConquerDL(c, r, p, board))	||
            		 	 	 	 	 	 	  (canConquerDR(c, r, p, board))	||
            		 	 	 	 	 	 	  (canConquerUL(c, r, p, board)) 	||
            		 	 	 	 	 	 	  (canConquerUR(c, r, p, board))    );


             return canPut;

        }

//=======================================================================================
bool isEmpty(int c,int r,int** board){

             if(board[c][r] == 0)	//val 2 = empty
             { 	 return true;				}
             else
             { 	 return false;}
}
//=======================================================================================
int op(int p){
	if(p==1)
	{		return 0;	}
		else if (p == 0)
	{		return 1;	}

}

//=======================================================================================
int checkLine(int p, int initialColumn,
 int initialRow, int directionX, int directionY, int** board) {

// stores the value of the first position with a value different than
 // the player value
 int cline = p;
 bool resolved = false;

  int x = initialColumn;
    int y = initialRow;

cout << "x=" << x << "y="<<y <<endl;
   while (!resolved) {

 x += directionX;
    y += directionY;
   // if we are inside the bounds of the board game
      if (x >= 0 && x < 8 && y >= 0 && y < 8) {

  if (board[x][y] != p) {
        resolved = true;
          cline = board[x][y];
   }
 } else {
     // out of bounds means resolved with no different position
  resolved = true;
  }
  }
cout << "cline(conquer ends at):" <<x <<"|"<< y << endl;
 return cline;
  }
//=======================================================================================

bool canConquerDL(int c, int r,int p, int** board){
	 bool enclosing = false;
     // impossible to conquer if space is less than 2
     if (c > 1 && r < 6 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c-1][r+1] == op(p)) {

                     int value = checkLine(op(p), (c-1), (r+1) , -1, +1, board);

                     enclosing = value ==p;

             }
     }
     return enclosing;
}

//=======================================================================================

bool canConquerDown(int c, int r,int p, int** board){
	 bool enclosing = false;
     // impossible to conquer if space is less than 2
     if (r <6 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c][r+1] == op(p)) {

                     int value = checkLine(op(p), c, (r+1) , 0, 1, board);
                     enclosing = value ==p;

             }
     }
     return enclosing;
}


//=======================================================================================
bool canConquerDR(int c, int r,int p, int** board){
	 bool enclosing = false;
     // impossible to conquer if space is less than 2
     if (c < 6 && r < 6 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c+1][r+1] == op(p)) {

                     int value = checkLine(op(p), (c+1), (r+1) ,1, 1, board);
                     enclosing = value ==p;

             }
     }
     return enclosing;
}




//=======================================================================================

bool canConquerLeft(int c, int r,int p, int** board){
	 bool enclosing = false;
     // impossible to conquer if space is less than 2
     if (c > 1 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c-1][r] == op(p)) {

                     int value = checkLine(op(p), (c-1), r ,-1,0, board);
                     enclosing = value == p;

             }
     }
     return enclosing;
}

//=======================================================================================

bool canConquerRight(int c, int r,int p, int** board){
	 bool enclosing = false;
     // impossible to conquer if space is less than 2
     if (c < 6 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c+1][r] == op(p)) {

                     int value = checkLine(op(p), (c+1), r ,1,0, board);
                     enclosing = value == p;

             }
     }
     return enclosing;
}


//=======================================================================================
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



//=======================================================================================

bool canConquerUp(int c, int r,int p, int** board){
	 bool enclosing = false;
     // impossible to conquer if space is less than 2
     if (r > 1) {

             // impossible to enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c][r-1] == op(p)) {

                     int value = checkLine( op(p), c, (r -1) ,0,-1, board);
                     enclosing = value;

             }
     }
     return enclosing;
}

//=======================================================================================
bool canConquerUR(int c, int r,int p, int** board){
	 bool enclosing = false;
     // impossible to conquer if space is less than 2
     if (c < 6 && r > 1 ) {

             // impossible enclose upwards if adjacent upwards chip is not
             // opponent
             if (board[c+1][r-1] == op(p)) {

                     int value = checkLine(op(p), (c+1), (r-1) ,1, -1, board);
                     enclosing = value ==p;

             }
     }
     return enclosing;
}



//=======================================================================================


int Conquer(int c, int r, int directionX, int directionY, int** board,int p)
{

                int x = c;
                int y = r;

                bool ownChip = false;


                //conquer until an own chip is found
                while ( !ownChip ) {
                        //advancing in the given direction
                        x += directionX;
                        y += directionY;

			cout << "x" << x << "y" << y << endl;
                        //if is not an own chip
                        if (board[x][y] != p) {
                                board[x][y] = p;
                        } else {
                                ownChip = true;
                        }
                }
        }
//=======================================================================================

void fixBoard(int c, int r,  int** board, int p)
{
if(canConquerUp(  c,  r, p, board ))
{	Conquer( c,  r, 0, -1,  board, p);	}

if(canConquerDown(  c,  r, p, board ))
{	Conquer( c,  r, 0, 1,  board, p);	}

if(canConquerLeft(  c,  r, p, board ))
{	Conquer( c,  r, -1, 0,  board, p);	}

if(canConquerRight(  c,  r, p, board ))
{	Conquer( c,  r, 1, 0,  board, p);	}

if(canConquerDL(  c,  r, p, board ))
{	Conquer( c,  r, -1, 1,  board, p);	}

if(canConquerDR(  c,  r, p, board ))
{	Conquer( c,  r, 1, 1,  board, p);	}

if(canConquerUL(  c,  r, p, board ))
{	Conquer( c,  r, -1, -1,  board, p);	}

if(canConquerUR(  c,  r, p, board ))
{	Conquer( c,  r, 1, -1,  board, p);	}
}


//=======================================================================================

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


