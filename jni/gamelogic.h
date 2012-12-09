/*


#ifndef FIRST_H
#define FIRST_H

extern int first(int  x, int  y);

#endif // FIRST_H
 */

#ifndef GAMELOGIC_H
#define GAMELOGIC_H


extern int  op(int player);
extern int checkLine(int player, int x, int y, int directionX, int directionY);


extern bool isValid(int x, int y, int board[8][8], int player);
extern bool isEmpty(int board[8][8]);

extern bool canConquerUp(int x, int y, int player);


extern bool IsMoveAllowed(int x, int y, int board[8][8], int player);






#endif //gamelogic
