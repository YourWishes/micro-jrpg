/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"

typedef struct entity_s entity_t;

/**
 * Ticks player input logic.
 * 
 * @param entity Pointer to the player entity.
 */
void playerTickInput(entity_t *entity);