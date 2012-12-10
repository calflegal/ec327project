#include <jni.h>
#include <gamestate.h>

extern "C"{

void fixBoard(int c, int r,  int** board, int p)
{

if(canConquerUp(  c,  r, p, board ))
{
	Conquer( c,  r, 0, -1,  board, p);
}



}









