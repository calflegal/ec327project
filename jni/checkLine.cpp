#include <jni>
#include "gamelogic.h"




int checkLine(int p, int initialColumn,
 int initialRow, int directionX, int directionY) {

// stores the value of the first position with a value different than
 // the player value
 int cline = player;
 boolean resolved = false;

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

