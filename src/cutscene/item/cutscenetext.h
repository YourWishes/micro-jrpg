/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"

#define CUTSCENE_TEXT_BUFFER 256

typedef const char_t *cutscenetext_t;

typedef struct cutscenetextdata_s {
  char_t buffer[CUTSCENE_TEXT_BUFFER];
  uint8_t length;
  uint8_t scroll;
} cutscenetextdata_t;