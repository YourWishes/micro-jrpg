/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "game.h"

game_t GAME;

void gameInit() {
  memset(&GAME, 0, sizeof(GAME));

  entityInit(&GAME.player, ENTITY_TYPE_PLAYER);

  GAME.scene = SCENE_OVERWORLD;
}

void gameTick() {
  sceneTick();
}