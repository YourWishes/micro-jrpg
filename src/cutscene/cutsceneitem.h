/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "cutscenewait.h"
#include "cutscenecallback.h"
#include "cutscenetext.h"

#define CUTSCENE_ITEM_NULL 0
#define CUTSCENE_ITEM_TEXT 1
#define CUTSCENE_ITEM_CALLBACK 2
#define CUTSCENE_ITEM_WAIT 3

typedef struct cutsceneitem_s {
  uint8_t type;

  // Arguments/Data that will be used when this item is invoked.
  union {
    cutscenetext_t text;
    cutscenecallback_t callback;
    cutscenewait_t wait;
  };
} cutsceneitem_t;

typedef union {
  cutscenewaitdata_t wait;
} cutsceneitemdata_t;

/**
 * Start the given cutscene item.
 * 
 * @param item The cutscene item to start.
 * @param data The cutscene item data storage.
 */
void cutsceneItemStart(const cutsceneitem_t *item, cutsceneitemdata_t *data);

/**
 * Tick the given cutscene item (one frame).
 * 
 * @param item The cutscene item to tick.
 * @param data The cutscene item data storage.
 */
void cutsceneItemTick(const cutsceneitem_t *item, cutsceneitemdata_t *data);