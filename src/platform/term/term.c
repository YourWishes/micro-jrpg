/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "term.h"
#include "game.h"

void termDrawOverworld() {
  // Draw map.

  termDrawEntity(&GAME.player);

  entity_t *start = GAME.overworld.map.entities;
  entity_t *end = start + MAP_ENTITY_COUNT;
  while(start < end) {
    if(start->type != ENTITY_TYPE_NULL) termDrawEntity(start);
    start++;
  }
}

void termDrawEntity(const entity_t *ent) {
  // Placeholder: Draw entity at its position
  char c;
  switch(ent->direction) {
    case DIRECTION_NORTH:
      c = '^';
      break;
    case DIRECTION_EAST:
      c = '>';
      break;
    case DIRECTION_SOUTH:
      c = 'v';
      break;
    case DIRECTION_WEST:
      c = '<';
      break;
    default:
      c = '@';
      break;
  }

  termPushChar
}

void termDraw() {
  termClear();



  termFlush();
}