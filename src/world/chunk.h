/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "world/tile.h"

#define CHUNK_WIDTH_IN_TILES 16
#define CHUNK_HEIGHT_IN_TILES 16
#define CHUNK_TILE_COUNT (CHUNK_WIDTH_IN_TILES * CHUNK_HEIGHT_IN_TILES)

typedef struct chunk_s {
  tile_t tiles[CHUNK_TILE_COUNT];
} chunk_t;