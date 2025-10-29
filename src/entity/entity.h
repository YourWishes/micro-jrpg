/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "entity/direction.h"
#include "entity/entitytype.h"
#include "player.h"
#include "sign.h"

#define ENTITY_ANIM_NONE 0
#define ENTITY_ANIM_WALK 1

#define ENTITY_ANIM_WALK_DURATION 8

typedef struct entity_s {
  struct {
    // Relative to top-left position of the top-left chunk of the map.
    uint8_t x, y;
  } position;

  direction_t direction;
  entitytype_t type;

  uint8_t animation;
  union {
    uint8_t animWalk;
  };

  union {
    sign_t sign;
  };
} entity_t;

/**
 * Initialize an entity.
 * 
 * @param entity Pointer to the entity to initialize.
 * @param type The type of the entity.
 */
void entityInit(entity_t *entity, const entitytype_t type);

/**
 * Update an entity for one tick.
 * 
 * @param entity Pointer to the entity to update.
 */
void entityTick(entity_t *entity);

/**
 * Turn an entity to face a new direction.
 * 
 * @param entity Pointer to the entity to turn.
 * @param direction The direction to face.
 */
void entityTurn(entity_t *entity, const direction_t direction);

/**
 * Make an entity walk in a direction.
 * 
 * @param entity Pointer to the entity to make walk.
 * @param direction The direction to walk in.
 */
void entityWalk(entity_t *entity, const direction_t direction);

/**
 * Receive interaction from player.
 * 
 * @param entity Pointer to the entity being interacted with.
 */
void entityInteract(entity_t *entity);