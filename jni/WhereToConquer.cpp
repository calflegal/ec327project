#include <jni.h>
#include "gamelogic.h"




			void conquerPosition(int player, int c, int r) {

               //if chooses conquer direction
                if (isValid.canConquerUP(c, r, p)) {
                        this.conquer(player, c, r, 0, -1);
                }

}
