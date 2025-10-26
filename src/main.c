/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "game.h"
#if RPG_TERM == 1
#include "term/term.h"
#endif

int main(int argc, char** argv) {
  gameInit();

  #if RPG_TERM == 1
    termInit();
  #endif

  while(1) {
    #if RPG_TERM == 1
      termUpdate();
    #endif

    gameTick();

    #if RPG_TERM == 1
      termDraw();
    #endif
  }

  #if RPG_TERM == 1
    termDispose();
  #endif

  return 0;
}