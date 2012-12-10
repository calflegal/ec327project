#include <jni.h>
#include <gamestate.h>

extern "C"{


void Java_com_ec327cassio_reversi_MainActivity_fixBoard(jint board[][])
{


if(canConquerUp)
{
	Conquer(int c, int r, 0, -1, p, board);
}
if(canConquerDOWN)
{
	Conquer(int c, int r, 0,  1, p, board);
}


}

}










