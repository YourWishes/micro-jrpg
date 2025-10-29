/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "cutscene/cutscene.h"

static void testCutsceneTest() {
}

static const cutsceneitem_t TEST_CUTSCENE_ITEMS[] = {
  { .type = CUTSCENE_ITEM_WAIT, .wait = 1 * GAME_TIME_TICKS_PER_SECOND }
};

static const cutscene_t TEST_CUTSCENE = {
  .items = TEST_CUTSCENE_ITEMS,
  .itemCount = sizeof(TEST_CUTSCENE_ITEMS) / sizeof(cutsceneitem_t)
};