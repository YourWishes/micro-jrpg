/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "cutscene/cutscene.h"

typedef struct entity_s entity_t;

typedef struct sign_s {
  const cutscene_t *cutscene;
} sign_t;

/**
 * Receive interaction from player.
 * 
 * @param entity Pointer to the entity being interacted with.
 */
void signInteract(entity_t *entity);