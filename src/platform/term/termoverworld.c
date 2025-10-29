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

  // Draw UI
  termDrawUI(chars, colors, w, h);
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

void termDrawUI(
  char_t *chars,
  termcolor_t *colors,
  const int32_t w,
  const int32_t h
) {
  // Textbox.
  const cutsceneitem_t *csItem = cutsceneGetCurrentItem();
  if(csItem != NULL && csItem->type == CUTSCENE_ITEM_TEXT) {
    // Draw box
    int32_t boxHeight = 5;
    for(int32_t y = h - boxHeight; y < h; y++) {
      for(int32_t x = 0; x < w; x++) {
        size_t index = y * w + x;
        if(y == h - boxHeight || y == h - 1) {
          chars[index] = '-';
        } else if(x == 0 || x == w - 1) {
          chars[index] = '|';
        } else {
          chars[index] = ' ';
        }
        colors[index] = TERM_COLOR_WHITE;
      }
    }

    // Draw text
    cutscenetextdata_t *data = &GAME.cutsceneSystem.data.text;
    int boxRows = boxHeight - 2;
    int boxCols = w - 2;
    int row = 0, col = 0;
    for(uint8_t i = 0; i < data->scroll; i++) {
      char ch = data->buffer[i];
      if(ch == '\n') {
        row++;
        col = 0;
        if(row >= boxRows) break;
        continue;
      }
      if(col >= boxCols) {
        row++;
        col = 0;
        if(row >= boxRows) break;
      }
      size_t boxIndex = (h - boxHeight + 1 + row) * w + 1 + col;
      if(boxIndex >= (size_t)(h * w)) break;
      chars[boxIndex] = ch;
      colors[boxIndex] = TERM_COLOR_WHITE;
      col++;
    }
  }
}