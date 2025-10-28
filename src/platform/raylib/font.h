/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"
#include <raylib.h>

#define FONT_COLUMN_COUNT 16
#define FONT_ROW_COUNT 8
#define FONT_CHAR_SPACING 0// Font has built in spacing
#define FONT_SCALE 3.0f

typedef struct font_s {
  Texture2D texture;
  Image image;
  int32_t charWidthRaw;
  int32_t charHeightRaw;
  int32_t charWidth;
  int32_t charHeight;
} font_t;

extern font_t FONT;

/**
 * Initializes the font.
 */
int32_t fontInit();

/**
 * Draws a character at the specified position.
 * 
 * @param c The character to draw.
 * @param x The x position.
 * @param y The y position.
 * @param color The color to draw the character with.
 */
void fontDraw(
  const char_t c, const float_t x, const float_t y, const Color color
);

/**
 * Draws a string at the specified position. No wrapping is performed.
 * 
 * @param str The string to draw.
 * @param x The x position.
 * @param y The y position.
 * @param color The color to draw the string with.
 */
void fontDrawString(
  const char_t *str, const float_t x, const float_t y, const Color color
);

/**
 * Disposes of the font.
 */
void fontDispose();