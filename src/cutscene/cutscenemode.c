/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "cutscenemode.h"
#include "game.h"

bool_t cutsceneModeIsInputAllowed() {
  switch(GAME.cutsceneSystem.mode) {
    case CUTSCENE_MODE_FULL_FREEZE:
    case CUTSCENE_MODE_INPUT_FREEZE:
      return false;
      
    default:
      return true;
  }
}