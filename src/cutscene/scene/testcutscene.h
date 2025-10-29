/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "cutscene/cutscene.h"

static const cutsceneitem_t TEST_CUTSCENE_ONE_ITEMS[] = {
  { .type = CUTSCENE_ITEM_TEXT, .text = "This is a test cutscene." },
  { .type = CUTSCENE_ITEM_WAIT, .wait = 2 * GAME_TIME_TICKS_PER_SECOND },
  { .type = CUTSCENE_ITEM_TEXT, .text = "It has multiple lines of text.\nAnd waits in between." },
};

static const cutscene_t TEST_CUTSCENE_ONE = {
  .items = TEST_CUTSCENE_ONE_ITEMS,
  .itemCount = sizeof(TEST_CUTSCENE_ONE_ITEMS) / sizeof(cutsceneitem_t)
};

static const cutsceneitem_t TEST_CUTSCENE_TWO_ITEMS[] = {
  { .type = CUTSCENE_ITEM_WAIT, .wait = 1 * GAME_TIME_TICKS_PER_SECOND },
  { .type = CUTSCENE_ITEM_CUTSCENE, .cutscene = &TEST_CUTSCENE_ONE },
};

static const cutscene_t TEST_CUTSCENE = {
  .items = TEST_CUTSCENE_TWO_ITEMS,
  .itemCount = sizeof(TEST_CUTSCENE_TWO_ITEMS) / sizeof(cutsceneitem_t)
};