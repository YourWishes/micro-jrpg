/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "cutscene/cutscene.h"
#include "input.h"

void cutsceneItemStart(const cutsceneitem_t *item, cutsceneitemdata_t *data) {
  switch(item->type) {
    case CUTSCENE_ITEM_TEXT: {
      strncpy(data->text.buffer, item->text, CUTSCENE_TEXT_BUFFER);
      data->text.length = strlen(data->text.buffer);
      break;
    }

    case CUTSCENE_ITEM_WAIT:
      data->wait = item->wait;
      break;

    case CUTSCENE_ITEM_CALLBACK:
      if(item->callback != NULL) item->callback();
      break;

    case CUTSCENE_ITEM_CUTSCENE:
      if(item->cutscene != NULL) cutsceneStart(item->cutscene);
      break;

    default:
      break;
  }
}

void cutsceneItemTick(const cutsceneitem_t *item, cutsceneitemdata_t *data) {
  switch(item->type) {
    // Scroll text, when finished scrolling, wait for A press.
    case CUTSCENE_ITEM_TEXT: {
      if(data->text.scroll < data->text.length) {
        data->text.scroll++;
      } else if(inputPressed(INPUT_ACTION_A)) {
        cutsceneNext();
      }
      break;
    }

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