#include <jni.h>
#include "gamelogic.h"





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


                        //if is not an own chip
                        if (board[x][y] != p) {
                                board[x][y] = p;
                        } else {
                                ownChip = true;
                        }
                }
        };
