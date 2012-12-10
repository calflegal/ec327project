#include <jni>
#include "gamelogic.h"




int checkLine(int p, int initialColumn,
 int initialRow, int directionX, int directionY, int** board) {

// stores the value of the first position with a value different than
 // the player value
 int cline = p;
 bool resolved = false;

  int x = initialColumn;
    int y = initialRow;


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

 return cline;
  }
