// check whether player can the piece here
#include <jni.h>





 bool checkSetChess(int p, int[][] chessList) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (chessList[i][j] < 0 && setChessCheck(i, j, p, chessList,
                        false)) {
                    return true;
                }
            }
        }
        return false;
    }



        public boolean isEnclosingUpwards(int player, int col, int row) {

                boolean enclosing = false;

                // impossible enclose upwards if row is less than 2
                if (row > 1) {

                        // impossible enclose upwards if adjacent upwards chip is not
                        // opponent
                        if (this.gameMatrix[col][row - 1] == opponent(player)) {

                                int value = this.getFirstPositionDifferentThan(
                                                opponent(player), col, row - 1, Direction.X.NONE,
                                                Direction.Y.UP);
                                // only encloses if the first different than opponent is an own
                                // chip
                                enclosing = value == player;
                        }
                }
                return enclosing;
        }
//////////////////////////////////////////////////////
        private int getFirstPositionDifferentThan(int player, int initialColumn,
                              int initialRow, int directionX, int directionY) {

                      // stores the value of the first position with a value different than
                      // the player value
                      int differentPosition = player;

                      boolean resolved = false;

                      int x = initialColumn;
                      int y = initialRow;

                      while (!resolved) {

                              x += directionX;
                              y += directionY;
                              // if we are inside the bounds of the board game
                              if (x >= 0 && x < GameLogic.COLS && y >= 0 && y < GameLogic.COLS) {

                                      if (this.gameMatrix[x][y] != player) {
                                              resolved = true;
                                              differentPosition = this.gameMatrix[x][y];
                                      }
                              } else {
                                      // out of bounds means resolved with no different position
                                      resolved = true;
                              }
                      }

                      return differentPosition;

              }

