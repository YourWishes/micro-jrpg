/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "direction.h"

void directionGetRelative(const direction_t from, int8_t *outX, int8_t *outY) {
  switch(from) {
    case DIRECTION_NORTH:
      *outX = 0;
      *outY = -1;
      break;

    case DIRECTION_EAST:
      *outX = 1;
      *outY = 0;
      break;

    case DIRECTION_SOUTH:
      *outX = 0;
      *outY = 1;
      break;

    case DIRECTION_WEST:
      *outX = -1;
      *outY = 0;
      break;
  }
}