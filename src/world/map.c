/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "map.h"

void mapTick(map_t *map) {
  for(int i = 0; i < MAP_ENTITY_COUNT; i++) {
    entityTick(&map->entities[i]);
  }
}