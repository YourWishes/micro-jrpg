/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "entity.h"

void entityInit(entity_t *entity, const entitytype_t type) {
  memset(entity, 0, sizeof(entity_t));

  entity->type = type;
}

void entityTick(entity_t *entity) {
  if(entity->type == ENTITY_TYPE_NULL) return;

  // Let entities move (if they do)
  if(entity->type == ENTITY_TYPE_PLAYER) {
    playerTickInput(entity);
  }
}

void entityTurn(entity_t *entity, const direction_t direction) {
  // TODO: animation/delay.
  entity->direction = direction;
}

void entityWalk(entity_t *entity, const direction_t direction) {
  // TODO: Animation, delay, colission, result, etc.
  entity->direction = direction;

  switch(direction) {
    case DIRECTION_NORTH:
      entity->position.y--;
      break;
    case DIRECTION_EAST:
      entity->position.x++;
      break;
    case DIRECTION_SOUTH:
      entity->position.y++;
      break;
    case DIRECTION_WEST:
      entity->position.x--;
      break;
  }
}