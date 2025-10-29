/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"

typedef struct platformraylib_s {
  uint8_t inputCurrent;
  uint8_t inputPrevious;
} platformraylib_t;

extern platformraylib_t PLATFORM_RAYLIB;