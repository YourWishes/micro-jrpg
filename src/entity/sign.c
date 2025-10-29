/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "sign.h"
#include "entity.h"

void signInteract(entity_t *entity) {
  if(entity->sign.cutscene == NULL) return;
  cutsceneStart(entity->sign.cutscene);
}