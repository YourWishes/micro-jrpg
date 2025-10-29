/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "cutscene.h"
#include "game.h"

void cutsceneInit() {
  memset(&GAME.cutsceneSystem, 0, sizeof(GAME.cutsceneSystem));
}

void cutsceneStart(const cutscene_t *cutscene) {
  GAME.cutsceneSystem.cutscene = cutscene;
  GAME.cutsceneSystem.mode = CUTSCENE_MODE_INITIAL;
  GAME.cutsceneSystem.currentItem = 0xFF;// Set to 0xFF so start wraps.
  cutsceneNext();
}

void cutsceneTick() {
  if(GAME.cutsceneSystem.cutscene == NULL) return;

  const cutsceneitem_t *item = (
    &GAME.cutsceneSystem.cutscene->items[GAME.cutsceneSystem.currentItem]
  );
  cutsceneItemTick(item, &GAME.cutsceneSystem.data);
}

void cutsceneNext() {
  if(GAME.cutsceneSystem.cutscene == NULL) return;

  GAME.cutsceneSystem.currentItem++;

  // End of the cutscene?
  if(GAME.cutsceneSystem.currentItem >= GAME.cutsceneSystem.cutscene->itemCount) {
    GAME.cutsceneSystem.cutscene = NULL;
    GAME.cutsceneSystem.currentItem = 0;
    GAME.cutsceneSystem.mode = CUTSCENE_MODE_NONE;
    return;
  }

  // Start item.
  const cutsceneitem_t *item = (
    &GAME.cutsceneSystem.cutscene->items[GAME.cutsceneSystem.currentItem]
  );
  cutsceneItemStart(item, &GAME.cutsceneSystem.data);
}