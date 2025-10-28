/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "game.h"
#include "platform/platform.h"

int main(int argc, char** argv) {
  gameInit();
  platformInit();

  while(1) {
    platformUpdate();

    gameTick();

    platformDraw();
  }

  platformDispose();
  return 0;
}