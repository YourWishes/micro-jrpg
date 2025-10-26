/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "input.h"

bool_t inputPressed(const uint8_t action) {
  return inputDown(action) && inputWasUp(action);
}

bool_t inputReleased(const uint8_t action) {
  return inputUp(action) && inputWasDown(action);
}