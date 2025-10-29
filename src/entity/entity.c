/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "entity.h"
#include "game.h"

void entityInit(entity_t *entity, const entitytype_t type) {
  memset(entity, 0, sizeof(entity_t));

  entity->type = type;
}

void entityTick(entity_t *entity) {
  if(entity->type == ENTITY_TYPE_NULL) return;

  // Handle animation
  switch(entity->animation) {
    case ENTITY_ANIM_WALK:
      entity->animWalk--;
      if(entity->animWalk == 0) {
        entity->animation = ENTITY_ANIM_NONE;
      }
      return;

    default:
      break;
  }

  // Let entities move (if they do)
  if(entity->type == ENTITY_TYPE_PLAYER && cutsceneModeIsInputAllowed()) {
    playerTickInput(entity);
  }
}

void entityTurn(entity_t *entity, const direction_t direction) {
  // TODO: animation/delay.
  entity->direction = direction;
}

void entityWalk(entity_t *entity, const direction_t direction) {
  // TODO: Animation, delay, etc.
  entity->direction = direction;

  // Where are we moving?
  uint8_t newX, newY;
  newX = entity->position.x;
  newY = entity->position.y;
  {
    int8_t relX, relY;
    directionGetRelative(direction, &relX, &relY);
    newX += relX;
    newY += relY;
  }

  // TODO: Tile in way?
  // TODO: Map bounds in way?

  // Entity in way?
  entity_t *start = GAME.overworld.map.entities;
  entity_t *end = start + MAP_ENTITY_COUNT;
  while(start < end) {
    if(
      start == entity ||
      entity->type == ENTITY_TYPE_NULL ||
      start->position.x != newX ||
      start->position.y != newY
    ) {
      start++;
      continue;
    }

    return;// Blocked
  }

  // Player in way?
  entity_t *player = &GAME.player;
  if(
    entity != player &&
    player->position.x == newX &&
    player->position.y == newY
  ) {
    return;// Blocked
  }

  // Move.
  entity->position.x = newX;
  entity->position.y = newY;

  entity->animation = ENTITY_ANIM_WALK;
  entity->animWalk = ENTITY_ANIM_WALK_DURATION;// TODO: Running vs walking
}

void entityInteract(entity_t *entity) {
  switch(entity->type) {
    case ENTITY_TYPE_SIGN:
      signInteract(entity);
      break;

    default:
      break;
  }
}