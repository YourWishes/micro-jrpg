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

  entityInit(&GAME.overworld.map.entities[0], ENTITY_TYPE_SIGN);
  GAME.overworld.map.entities[0].position.x = 5;
  GAME.overworld.map.entities[0].position.y = 5;

  GAME.scene = SCENE_OVERWORLD;
}

void gameTick() {
  gameTimeTick(&GAME.time);
  sceneTick();
}