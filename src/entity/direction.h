/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"

#define DIRECTION_UP 0
#define DIRECTION_RIGHT 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3

#define DIRECTION_NORTH DIRECTION_UP
#define DIRECTION_EAST DIRECTION_RIGHT
#define DIRECTION_SOUTH DIRECTION_DOWN
#define DIRECTION_WEST DIRECTION_LEFT

typedef uint8_t direction_t;

/**
 * Get the relative x and y offsets for a given direction.
 * 
 * @param from The direction to get offsets for.
 * @param outX Pointer to store the x offset.
 * @param outY Pointer to store the y offset.
 */
void directionGetRelative(const direction_t from, int8_t *outX, int8_t *outY);