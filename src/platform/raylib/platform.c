/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "platform/platform.h"
#include <raylib.h>
#include "font.h"
#include "platform/term/term.h"

uint8_t platformInit(void) {
  InitWindow(800, 600, "Micro JRPG");
  SetTargetFPS(60);

  if(fontInit() != 0) return PLATFORM_ERROR;

  SetWindowSize(40 * FONT.charWidth, 30 * FONT.charHeight);

  return PLATFORM_OK;
}

uint8_t platformUpdate() {
  if(WindowShouldClose()) {
    return PLATFORM_EXIT;
  }
  
  return PLATFORM_OK;
}

void platformDraw() {
  BeginDrawing();
  ClearBackground(BLACK);
  
  termDraw();

  EndDrawing();
}

void platformDispose() {
  fontDispose();
  CloseWindow();
}