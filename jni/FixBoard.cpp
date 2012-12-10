#include <jni.h>
#include <gamestate.h>


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
};









