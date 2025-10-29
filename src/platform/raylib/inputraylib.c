/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "input.h"
#include "platformraylib.h"
  
bool_t inputDown(const uint8_t action) {
  return (PLATFORM_RAYLIB.inputCurrent & action) != 0;
}

bool_t inputUp(const uint8_t action) {
  return (PLATFORM_RAYLIB.inputCurrent & action) == 0;
}

bool_t inputWasDown(const uint8_t action) {
  return (PLATFORM_RAYLIB.inputPrevious & action) != 0;
}

bool_t inputWasUp(const uint8_t action) {
  return (PLATFORM_RAYLIB.inputPrevious & action) == 0;
}