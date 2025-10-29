/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "platform/platform.h"
#include "platform/term/term.h"
#include "platform/tty/platformtty.h"
#include "input.h"
#include <time.h>

typedef struct ttyinputmap_s {
  int key;
  uint8_t action;
} ttyinputmap_t;

static const ttyinputmap_t TERM_INPUT_MAP[] = {
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

platformtty_t PLATFORM_TTY;

uint8_t platformInit() {
  memset(&PLATFORM_TTY, 0, sizeof(platformtty_t));

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  curs_set(0);
  start_color();
  use_default_colors();

  // Color Pairs
  init_pair(TERM_COLOR_BLACK, COLOR_BLACK, -1);
  init_pair(TERM_COLOR_RED, COLOR_RED, -1);
  init_pair(TERM_COLOR_GREEN, COLOR_GREEN, -1);
  init_pair(TERM_COLOR_YELLOW, COLOR_YELLOW, -1);
  init_pair(TERM_COLOR_BLUE, COLOR_BLUE, -1);
  init_pair(TERM_COLOR_MAGENTA, COLOR_MAGENTA, -1);
  init_pair(TERM_COLOR_CYAN, COLOR_CYAN, -1);
  init_pair(TERM_COLOR_WHITE, COLOR_WHITE, -1);
  

  // Set in-game time to real world time.
  time_t now = time(NULL);
  struct tm *t = localtime(&now);

  GAME.time.days = t->tm_wday;
  GAME.time.hours = t->tm_hour;
  GAME.time.minutes = t->tm_min;
  GAME.time.seconds = t->tm_sec;

  return PLATFORM_OK;
}

uint8_t platformUpdate() {
  PLATFORM_TTY.inputPrevious = PLATFORM_TTY.inputCurrent;
  PLATFORM_TTY.inputCurrent = 0;

  int ch = getch();
  if(ch == ERR) {
    PLATFORM_TTY.lastch = ERR;
    return PLATFORM_OK;
  }

  if(ch == PLATFORM_TTY.lastch) {
    return PLATFORM_OK;
  }
  PLATFORM_TTY.lastch = ch;

  const ttyinputmap_t *map = TERM_INPUT_MAP;
  while(map->key != -1) {
    if(map->key == ch) {
      PLATFORM_TTY.inputCurrent |= map->action;
      break;
    }
    map++;
  }

  return PLATFORM_OK;
}

void platformDraw() {
  clear();
  
  termDraw();

  attroff(COLOR_PAIR(1));
  refresh();
  
  // 16ms delay (60FPS)
  napms(16);
}

void platformDispose() {
  endwin();
}