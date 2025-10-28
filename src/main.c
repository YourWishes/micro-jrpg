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
  if(platformInit() != PLATFORM_OK) return 1;

  while(1) {
    if(platformUpdate() != PLATFORM_OK) break;

    gameTick();

    platformDraw();
  }

  platformDispose();
  return 0;
}