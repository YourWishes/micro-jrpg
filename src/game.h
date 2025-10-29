/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "entity/entity.h"
#include "world/map.h"
#include "scene/scene.h"
#include "cutscene/cutscene.h"
#include "gametime.h"

#define GAME_SCENE_INITIAL 0
#define GAME_SCENE_OVERWORLD 1

typedef struct game_s {
  scene_t scene;
  entity_t player;
  gametime_t time;
  cutscenesystem_t cutsceneSystem;

  union {
    struct {
      map_t map;
    } overworld;
  };
} game_t;

extern game_t GAME;

/**
 * Initialize the game state.
 */
void gameInit();

/**
 * Advance the game state by one tick. Should be called at 60Hz.
 */
void gameTick();