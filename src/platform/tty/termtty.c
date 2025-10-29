/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "platform/term/term.h"
#include <ncurses.h>

void termClear() {
  clear();
  refresh();
}

void termFlush() {
  // Nothing to do
}

uint8_t termGetColumnCount() {
  int cols = getmaxx(stdscr);
  return (uint8_t)cols;
}

uint8_t termGetRowCount() {
  int rows = getmaxy(stdscr);
  return (uint8_t)rows;
}

void termPushColor(termcolor_t color) {
  // Map the termcolor_t to the ncurses color pair
  attron(COLOR_PAIR((int)color));
}

void termPushChar(char_t c) {
  addch(c);
}