#include <jni.h>
#include "gamelogic.h"




int Conquer(int c, int r, int directionX, int directionY, p, int* board)
{

                int x = c;
                int y = r;
                bool ownChip = false;

             //   int[][] board = gboard();

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
