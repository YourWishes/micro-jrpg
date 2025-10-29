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
  
  entity_t *ent = &GAME.player;
  entityInit(ent, ENTITY_TYPE_PLAYER);
  
  ent = &GAME.overworld.map.entities[0];
  entityInit(ent, ENTITY_TYPE_SIGN);
  ent->position.x = 5;
  ent->position.y = 5;
  ent->sign.cutscene = &TEST_CUTSCENE;

  GAME.scene = SCENE_OVERWORLD;
}

void gameTick() {
  gameTimeTick(&GAME.time);
  sceneTick();
  cutsceneTick();
}