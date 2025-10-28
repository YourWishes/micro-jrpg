/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "font.h"
#include "assets/font.h"

font_t FONT;

int32_t fontInit() {
  memset(&FONT, 0, sizeof(FONT));
  
  FONT.image = LoadImageFromMemory(".png", FONT_DATA, FONT_SIZE);
  if(FONT.image.data == NULL) {
    printf("Failed to load font image from memory.\n");
    return -1; // Failed to load image
  }

  FONT.texture = LoadTextureFromImage(FONT.image);
  if(FONT.texture.id == 0) {
    printf("Failed to load font texture from image.\n");
    UnloadImage(FONT.image);
    return -1; // Failed to load texture
  }

  FONT.charWidthRaw = FONT.texture.width / FONT_COLUMN_COUNT;
  FONT.charHeightRaw = FONT.texture.height / FONT_ROW_COUNT;
  FONT.charWidth = FONT.charWidthRaw * FONT_SCALE;
  FONT.charHeight = FONT.charHeightRaw * FONT_SCALE;

  return 0;
}

void fontDraw(
  const char_t c, const float_t x, const float_t y, const Color color
) {
  int32_t charAdjusted = (int32_t)c - 1;
  if(c >= '`') charAdjusted += 1;// For some reason the font has empty slot?

  int32_t col = (charAdjusted % FONT_COLUMN_COUNT);
  int32_t row = (charAdjusted / FONT_COLUMN_COUNT);

  Rectangle sourceRec = {
    .x = (float_t)(col * FONT.charWidthRaw),
    .y = (float_t)(row * FONT.charHeightRaw),
    .width = (float_t)FONT.charWidthRaw,
    .height = (float_t)FONT.charHeightRaw
  };
  Rectangle destRec = {
    .x = x,
    .y = y,
    .width = (float_t)FONT.charWidth,
    .height = (float_t)FONT.charHeight
  };

  DrawTexturePro(
    FONT.texture, sourceRec, destRec, (Vector2){0, 0}, 0.0f, color
  );
}

void fontDrawString(
  const char_t *str, const float_t x, const float_t y, const Color color
) {
  float_t cx, cy;
  cx = x;
  cy = y;

  const char_t *c = (char_t *)str;
  while(*c) {
    if(*c == '\n') {
      cx = x;
      cy += (float_t)(FONT.charHeight + FONT_CHAR_SPACING);
      c++;
      continue;
    }

    fontDraw(*c, cx, cy, color);
    cx += (float_t)(FONT.charWidth + FONT_CHAR_SPACING);
    c++;
  }
}

void fontDispose() {
  UnloadTexture(FONT.texture);
  UnloadImage(FONT.image);
}