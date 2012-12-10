/*
#ifndef FIRST_H
#define FIRST_H

extern int first(int  x, int  y);

#endif // FIRST_H
 */

//#ifndef GAMELOGIC_H
//#define GAMELOGIC_H



int  op(int player);
int checkLine(int player, int x, int y, int directionX, int directionY,int** board);



 bool isValid(int x, int y, int**board, int player);
 bool isEmpty(int c, int r,int** board);

 bool canConquerUp(int x, int y, int player,int** board);
 bool canConquerDown(int x, int y, int player,int** board);
 bool canConquerLeft(int x, int y, int player,int** board);
 bool canConquerRight(int x, int y, int player,int** board);
 bool canConquerDL(int x, int y, int player,int** board);
 bool canConquerDR(int x, int y, int player,int** board);
 bool canConquerUL(int x, int y, int player,int** board);
 bool canConquerUR(int x, int y, int player,int** board);

void fixBoard(int c, int r,  int** board, int p);


int Conquer(int c, int r, int x, int y, int p,int** board);





//#endif //gamelogic
