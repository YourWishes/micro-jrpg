/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "entity.h"
#include "input.h"

void playerTickInput(entity_t *entity) {
  if(inputPressed(INPUT_ACTION_UP)) {
    entityWalk(entity, DIRECTION_NORTH);
  } else if(inputPressed(INPUT_ACTION_DOWN)) {
    entityWalk(entity, DIRECTION_SOUTH);
  } else if(inputPressed(INPUT_ACTION_LEFT)) {
    entityWalk(entity, DIRECTION_WEST);
  } else if(inputPressed(INPUT_ACTION_RIGHT)) {
    entityWalk(entity, DIRECTION_EAST);
  }
}