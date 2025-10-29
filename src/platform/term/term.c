/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "term.h"
#include "termoverworld.h"

void termDraw() {
  termClear();

  int32_t width, height, x, y;
  width = termGetColumnCount();
  height = termGetRowCount();

  // Create buffers
  char_t *chars = malloc(width * height * sizeof(char_t));
  if(chars == NULL) {
    printf("termDrawOverworld: Out of memory!\n");
    abort();
    return;
  }
  memset(chars, ' ', width * height * sizeof(char_t));

  termcolor_t *colors = malloc(width * height * sizeof(termcolor_t));
  if(colors == NULL) {
    printf("termDrawOverworld: Out of memory!\n");
    free(chars);
    abort();
    return;
  }
  memset(colors, TERM_COLOR_WHITE, width * height * sizeof(termcolor_t));

  // Draw
  termDrawOverworld(chars, colors, width, height);

  // Print
  size_t i;
  termcolor_t curColor = TERM_COLOR_WHITE;
  for(size_t i = 0; i < width * height; i++) {
    if(colors[i] != curColor) {
      termPushColor(colors[i]);
      curColor = colors[i];
    }
    termPushChar(chars[i]);
  }
  
  // Clean up
  free(chars);
  free(colors);

  termFlush();
}