/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "term.h"
#include "input.h"

typedef struct terminputmap_s {
  int key;
  uint8_t action;
} terminputmap_t;

static const terminputmap_t TERM_INPUT_MAP[] = {
  { KEY_UP, INPUT_ACTION_UP },
  { 'w', INPUT_ACTION_UP },
  { KEY_DOWN, INPUT_ACTION_DOWN },
  { 's', INPUT_ACTION_DOWN },
  { KEY_LEFT, INPUT_ACTION_LEFT },
  { 'a', INPUT_ACTION_LEFT },
  { KEY_RIGHT, INPUT_ACTION_RIGHT },
  { 'd', INPUT_ACTION_RIGHT },
  { 'j', INPUT_ACTION_A },
  { 'e', INPUT_ACTION_A },
  { 'k', INPUT_ACTION_B },
  { 'q', INPUT_ACTION_B },
  { KEY_ENTER, INPUT_ACTION_START },
  { ' ', INPUT_ACTION_SELECT },
  { -1, 0 }
};

term_t TERM;

void termInit() {
  memset(&TERM, 0, sizeof(TERM));

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  curs_set(0);
  start_color();
  use_default_colors();
  init_pair(1, COLOR_GREEN, -1);
}

void termUpdate() {
  TERM.inputPrevious = TERM.inputCurrent;
  TERM.inputCurrent = 0;

  int ch = getch();
  if(ch == ERR) {
    TERM.lastch = ERR;
    return;
  }

  if(ch == TERM.lastch) {
    return;
  }
  TERM.lastch = ch;

  const terminputmap_t *map = TERM_INPUT_MAP;
  while(map->key != -1) {
    if(map->key == ch) {
      TERM.inputCurrent |= map->action;
      break;
    }
    map++;
  }
}

void termDraw() {
  clear();
  attron(COLOR_PAIR(1));

  termDrawEntity(&GAME.player);

  attroff(COLOR_PAIR(1));
  refresh();
  
  // 16ms delay (60FPS)
  napms(16);
}

void termDrawEntity(const entity_t *ent) {
  // Placeholder: Draw entity at its position
  mvaddch(ent->position.y, ent->position.x, '@');
}

void termDispose() {
  endwin();
}