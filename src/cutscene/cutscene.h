/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "cutscene/item/cutsceneitem.h"
#include "cutscene/cutscenemode.h"

typedef struct cutscene_s {
  const cutsceneitem_t *items;
  uint8_t itemCount;
} cutscene_t;

typedef struct {
  const cutscene_t *cutscene;
  uint8_t currentItem;

  // Data (used by the current item).
  cutsceneitemdata_t data;
  cutscenemode_t mode;
} cutscenesystem_t;

/**
 * Initialize the cutscene system.
 */
void cutsceneInit();

/**
 * Start a cutscene.
 * 
 * @param cutscene Pointer to the cutscene to start.
 */
void cutsceneStart(const cutscene_t *cutscene);

/**
 * Advance to the next item in the cutscene.
 */
void cutsceneNext();

/**
 * Update the cutscene system for one tick.
 */
void cutsceneTick();

/**
 * Get the current cutscene item.
 * 
 * @return Pointer to the current cutscene item.
 */
const cutsceneitem_t * cutsceneGetCurrentItem();