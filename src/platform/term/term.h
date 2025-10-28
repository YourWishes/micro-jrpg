/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"
#include "termcolor.h"

/**
 * Common implementation to draw the game state to the terminal (whatever the
 * terminal implementation by the platform is).
 */
void termDraw();

/**
 * Clears the terminal screen and resets the cursor to the top left. Called at
 * the start of each "frame". Should also reset any terminal state (e.g. color).
 */
void termClear();

/**
 * Flushes any pending terminal operations. Called at the end of each "frame".
 */
void termFlush();

/**
 * Get the number of columns in the terminal.
 * 
 * @return The number of columns.
 */
uint8_t termGetColumnCount();

/**
 * Get the number of rows in the terminal.
 * 
 * @return The number of rows.
 */
uint8_t termGetRowCount();

/**
 * Push a color onto the terminal color stack.
 * 
 * @param color The color to push.
 */
void termPushColor(termcolor_t color);

/**
 * Push a character onto the terminal at the current cursor position. This will
 * also advance the cursor position by 1 character. Wrapping will be handled by
 * the terminal implementation.
 * 
 * @param c The character to push.
 */
void termPushChar(char_t c);