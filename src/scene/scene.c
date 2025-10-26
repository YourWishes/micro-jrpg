/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "scene.h"
#include "game.h"

void sceneTick() {
  switch(GAME.scene) {
    case SCENE_INITIAL: {
      break;
    }

    case SCENE_OVERWORLD: {
      mapTick(&GAME.overworld.map);
      entityTick(&GAME.player);
      break;
    }
  }
}