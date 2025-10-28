/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "entity.h"
#include "input.h"
#include "game.h"

void playerTickInput(entity_t *entity) {
  // Turn
  if(inputPressed(INPUT_ACTION_UP) && entity->direction != DIRECTION_NORTH) {
    return entityTurn(entity, DIRECTION_NORTH);
  }
  if(inputPressed(INPUT_ACTION_DOWN) && entity->direction != DIRECTION_SOUTH) {
    return entityTurn(entity, DIRECTION_SOUTH);
  }
  if(inputPressed(INPUT_ACTION_LEFT) && entity->direction != DIRECTION_WEST) {
    return entityTurn(entity, DIRECTION_WEST);
  }
  if(inputPressed(INPUT_ACTION_RIGHT) && entity->direction != DIRECTION_EAST) {
    return entityTurn(entity, DIRECTION_EAST);
  }

  // Walk
  if(inputDown(INPUT_ACTION_UP)) {
    return entityWalk(entity, DIRECTION_NORTH);
  }
  if(inputDown(INPUT_ACTION_DOWN)) {
    return entityWalk(entity, DIRECTION_SOUTH);
  }
  if(inputDown(INPUT_ACTION_LEFT)) {
    return entityWalk(entity, DIRECTION_WEST);
  }
  if(inputDown(INPUT_ACTION_RIGHT)) {
    return entityWalk(entity, DIRECTION_EAST);
  }

  // Interaction
  if(inputPressed(INPUT_ACTION_A)) {
    // Facing direction relative
    uint8_t targetX, targetY;
    {
      int8_t faceX, faceY;
      directionGetRelative(entity->direction, &faceX, &faceY);
      targetX = entity->position.x + faceX;
      targetY = entity->position.y + faceY;
    }

    // For each entity
    entity_t *start = GAME.overworld.map.entities;
    entity_t *end = start + MAP_ENTITY_COUNT;
    while(start < end) {
      if(
        start == entity ||
        start->type == ENTITY_TYPE_NULL ||
        start->position.x != targetX ||
        start->position.y != targetY
      ) {
        start++;
        continue;
      }

      // Interact
      entityInteract(start);
      return;
    }
  }
}