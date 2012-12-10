#include <jni.h>
#include "gamelogic.h"

bool isEmpty(int c,int r,int** board){

             if(board[c][r] == 0)	//val 2 = empty
             { cout << "isempty:t" <<c<<"r"<<r<<endl;
			 return true;
				}
             else
             { cout << "isempty:f" <<endl; 
			 return false;}
}