/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"
#include "game.h"
#include <ncurses.h>

typedef struct platformtty_s {
  uint8_t inputCurrent;
  uint8_t inputPrevious;
  int lastch;
} platformtty_t;

extern platformtty_t PLATFORM_TTY;