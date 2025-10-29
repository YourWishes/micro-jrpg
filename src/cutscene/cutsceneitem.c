/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "cutsceneitem.h"
#include "cutscene.h"

void cutsceneItemStart(const cutsceneitem_t *item, cutsceneitemdata_t *data) {
  switch(item->type) {
    case CUTSCENE_ITEM_TEXT:
      break;

    case CUTSCENE_ITEM_WAIT:
      data->wait = item->wait;
      break;

    case CUTSCENE_ITEM_CALLBACK:
      if(item->callback != NULL) item->callback();
      break;

    default:
      break;
  }
}

void cutsceneItemTick(const cutsceneitem_t *item, cutsceneitemdata_t *data) {
  switch(item->type) {
    case CUTSCENE_ITEM_TEXT:
      break;

    case CUTSCENE_ITEM_CALLBACK:
      break;

    case CUTSCENE_ITEM_WAIT:
      data->wait--;
      if(data->wait <= 0) {
        // Wait is over, proceed to next item.
        cutsceneNext();
      }
      break;

    default:
      break;
  }
}