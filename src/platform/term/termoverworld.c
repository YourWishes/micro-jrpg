/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "termoverworld.h"

void termDrawOverworld(
  char_t *chars,
  termcolor_t *colors,
  const int32_t w,
  const int32_t h
) {
  // Draw the ground
  for(int32_t x = 0; x < w; x++) {
    for(int32_t y = 0; y < h; y++) {
      size_t index = y * w + x;
      chars[index] = '.';
      colors[index] = TERM_COLOR_GREEN;
    }
  }

  // Draw entities
  termDrawEntity(&GAME.player, chars, colors, w, h);

  entity_t *start = GAME.overworld.map.entities;
  while(start != GAME.overworld.map.entities + MAP_ENTITY_COUNT) {
    termDrawEntity(start, chars, colors, w, h);
    start++;
  }
}

void termDrawEntity(
  const entity_t *ent,
  char_t *chars,
  termcolor_t *colors,
  const int32_t w,
  const int32_t h
) {
  if(ent->type == ENTITY_TYPE_NULL) return;

  if(ent->position.x >= w || ent->position.y >= h) return;

  int32_t index = ent->position.y * w + ent->position.x;

  if(ent->type == ENTITY_TYPE_PLAYER) {
    switch(ent->direction) {
      case DIRECTION_UP:
        chars[index] = '^';
        break;
      case DIRECTION_DOWN:
        chars[index] = 'v';
        break;
      case DIRECTION_LEFT:
        chars[index] = '<';
        break;
      case DIRECTION_RIGHT:
        chars[index] = '>';
        break;
      default:
        chars[index] = '@';
        break;
    }
    colors[index] = TERM_COLOR_WHITE;
  } else if(ent->type == ENTITY_TYPE_SIGN) {
    chars[index] = '!';
    colors[index] = TERM_COLOR_YELLOW;
  }
}