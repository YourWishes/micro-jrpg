/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "game.h"
#include "cutscene/cutscene.h"
#include "cutscene/scene/testcutscene.h"

game_t GAME;

void gameInit() {
  memset(&GAME, 0, sizeof(GAME));

  cutsceneInit();

  entityInit(&GAME.player, ENTITY_TYPE_PLAYER);

  entityInit(&GAME.overworld.map.entities[0], ENTITY_TYPE_SIGN);
  GAME.overworld.map.entities[0].position.x = 5;
  GAME.overworld.map.entities[0].position.y = 5;
  GAME.overworld.map.entities[0].sign.cutscene = &TEST_CUTSCENE;

  GAME.scene = SCENE_OVERWORLD;
}

void gameTick() {
  gameTimeTick(&GAME.time);
  cutsceneTick();
  sceneTick();
}