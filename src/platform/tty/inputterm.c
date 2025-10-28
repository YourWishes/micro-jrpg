/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "term.h"
  
bool_t inputDown(const uint8_t action) {
  return (TERM.inputCurrent & action) != 0;
}

bool_t inputUp(const uint8_t action) {
  return (TERM.inputCurrent & action) == 0;
}

bool_t inputWasDown(const uint8_t action) {
  return (TERM.inputPrevious & action) != 0;
}

bool_t inputWasUp(const uint8_t action) {
  return (TERM.inputPrevious & action) == 0;
}