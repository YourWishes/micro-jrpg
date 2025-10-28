/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "font.h"
#include "platform/term/term.h"

typedef struct termraylibcolormap_t {
  termcolor_t termColor;
  Color raylibColor;
} termraylibcolormap_t;

typedef struct termraylib_s {
  Color currentColor;
  float_t x, y;
} termraylib_t;

termraylibcolormap_t TERM_RAYLIB_COLORMAP[] = {
  { TERM_COLOR_BLACK,   BLACK },
  { TERM_COLOR_RED,     RED },
  { TERM_COLOR_GREEN,   GREEN },
  { TERM_COLOR_YELLOW,  YELLOW },
  { TERM_COLOR_BLUE,    BLUE },
  { TERM_COLOR_MAGENTA, MAGENTA },
  { TERM_COLOR_CYAN,    SKYBLUE },
  { TERM_COLOR_WHITE,   WHITE }
};

#define TERM_RAYLIB_INITIAL_COLOR WHITE

termraylib_t TERM_RAYLIB;

void termClear() {
  TERM_RAYLIB.currentColor = WHITE;
  TERM_RAYLIB.x = 0.0f;
  TERM_RAYLIB.y = 0.0f;
}

void termFlush() {
  // Nothing to do
}

uint8_t termGetColumnCount() {
  // Get Window width
  int32_t windowWidth = GetScreenWidth();
  return (uint8_t)(windowWidth / FONT.charWidth);
}

uint8_t termGetRowCount() {
  // Get Window height
  int32_t windowHeight = GetScreenHeight();
  return (uint8_t)(windowHeight / FONT.charHeight);
}

void termPushColor(termcolor_t color) {
  // Find the corresponding raylib color
  size_t colors = sizeof(TERM_RAYLIB_COLORMAP) / sizeof(termraylibcolormap_t);
  for(size_t i = 0; i < colors; i++) {
    if(TERM_RAYLIB_COLORMAP[i].termColor == color) {
      TERM_RAYLIB.currentColor = TERM_RAYLIB_COLORMAP[i].raylibColor;
      return;
    }
  }
}

void termPushChar(char_t c) {
  if(c == '\n') {
    TERM_RAYLIB.x = 0.0f;
    TERM_RAYLIB.y += (float_t)(FONT.charHeight + FONT_CHAR_SPACING);
    return;
  }

  fontDraw(c, TERM_RAYLIB.x, TERM_RAYLIB.y, TERM_RAYLIB.currentColor);
  TERM_RAYLIB.x += (float_t)(FONT.charWidth + FONT_CHAR_SPACING);

  // Wrapping
  if(TERM_RAYLIB.x + FONT.charWidth > (float_t)GetScreenWidth()) {
    TERM_RAYLIB.x = 0.0f;
    TERM_RAYLIB.y += (float_t)(FONT.charHeight + FONT_CHAR_SPACING);
  }
}