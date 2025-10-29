/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "platform/platform.h"
#include "platform/raylib/platformraylib.h"
#include <raylib.h>
#include "font.h"
#include "platform/term/term.h"
#include "input.h"
#include "game.h"
#include "gametime.h"
#include <time.h>

typedef struct rlkeyboardmap_t {
  uint8_t action;
  int32_t raylibKey;
} rlkeyboardmap_t;

static const rlkeyboardmap_t RL_KEYBOARD_MAP[] = {
  { INPUT_ACTION_UP, KEY_W },
  { INPUT_ACTION_UP, KEY_UP },
  { INPUT_ACTION_DOWN, KEY_S },
  { INPUT_ACTION_DOWN, KEY_DOWN },
  { INPUT_ACTION_LEFT, KEY_A },
  { INPUT_ACTION_LEFT, KEY_LEFT },
  { INPUT_ACTION_RIGHT, KEY_D },
  { INPUT_ACTION_RIGHT, KEY_RIGHT },
  { INPUT_ACTION_A, KEY_E },
  { INPUT_ACTION_B, KEY_Q },
  { INPUT_ACTION_START, KEY_ENTER },
  { INPUT_ACTION_START, KEY_SPACE },
  { INPUT_ACTION_SELECT, KEY_BACKSPACE },
  { 0x00, 0x00 }
};

platformraylib_t PLATFORM_RAYLIB;

uint8_t platformInit(void) {
  memset(&PLATFORM_RAYLIB, 0, sizeof(platformraylib_t));

  // Init raylib.
  InitWindow(800, 600, "Micro JRPG");
  SetTargetFPS(60);

  // Load font
  if(fontInit() != 0) return PLATFORM_ERROR;

  // Resize window
  SetWindowSize(40 * FONT.charWidth, 30 * FONT.charHeight);

  // Set in-game time to real world time.
  time_t now = time(NULL);
  struct tm *t = localtime(&now);

  GAME.time.days = t->tm_wday;
  GAME.time.hours = t->tm_hour;
  GAME.time.minutes = t->tm_min;
  GAME.time.seconds = t->tm_sec;

  return PLATFORM_OK;
}

uint8_t platformUpdate() {
  if(WindowShouldClose()) {
    return PLATFORM_EXIT;
  }

  // Update input state.
  PLATFORM_RAYLIB.inputPrevious = PLATFORM_RAYLIB.inputCurrent;
  PLATFORM_RAYLIB.inputCurrent = 0;
  const rlkeyboardmap_t *map = RL_KEYBOARD_MAP;
  do {
    if(IsKeyDown(map->raylibKey)) {
      PLATFORM_RAYLIB.inputCurrent |= map->action;
    }
    map++;
  } while(map->action != 0x00);

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