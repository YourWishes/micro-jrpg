/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"
#include "game.h"
#include <ncurses.h>

typedef struct term_s {
  uint8_t inputCurrent;
  uint8_t inputPrevious;
  int lastch;
} term_t;

extern term_t TERM;

/** 
 * Initialize the terminal subsystem.
 */
void termInit();

/** 
 * Update the terminal prior to game update.
 */
void termUpdate();

/** 
 * Draw the terminal game.
 */
void termDraw();

/** 
 * Draw the overworld scene.
 */
void termDrawOverworld();

/** 
 * Draw an entity to the terminal.
 * 
 * @param ent The entity to draw.
 */
void termDrawEntity(const entity_t *ent);

/** 
 * Dispose of the terminal subsystem.
 */
void termDispose();