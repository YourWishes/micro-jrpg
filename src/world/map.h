/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "world/chunk.h"
#include "entity/entity.h"

#define MAP_ENTITY_COUNT 8
#define MAP_WIDTH_IN_CHUNKS 3
#define MAP_HEIGHT_IN_CHUNKS 3
#define MAP_CHUNK_COUNT (MAP_WIDTH_IN_CHUNKS * MAP_HEIGHT_IN_CHUNKS)

typedef struct map_s {
  // Loaded chunks.
  chunk_t chunks[MAP_CHUNK_COUNT];
  chunk_t *order[MAP_CHUNK_COUNT];
  int8_t topLeftX, topLeftY;

  // Map entities
  entity_t entities[MAP_ENTITY_COUNT];

  // Size of map (in chunks)
  uint8_t width, height;
} map_t;

/**
 * Update the map for one tick.
 * 
 * @param map Pointer to the map to update.
 */
void mapTick(map_t *map);