/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"

#define CUTSCENE_ITEM_NULL 0
#define CUTSCENE_ITEM_TEXTBOX 1
#define CUTSCENE_ITEM_CALLBACK 2

typedef struct {
  uint8_t type;

  union {
    const char *textbox;
    void (*callback)(void);// TODO: Bring entity data across.
  };
} cutsceneitem_t;

typedef struct {
  cutsceneitem_t *items;
  uint8_t itemCount;
} cutscene_t;