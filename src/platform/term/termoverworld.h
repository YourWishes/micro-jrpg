/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "term.h"
#include "game.h"

/**
 * Draw the overworld SCENE to the terminal.
 * 
 * @param chars Buffer of characters to write to.
 * @param colors Buffer of colors to write to.
 * @param w Width of the terminal in characters.
 * @param h Height of the terminal in characters.
 */
void termDrawOverworld(
  char_t *chars,
  termcolor_t *colors,
  const int32_t w,
  const int32_t h
);

/**
 * Draw an entity to the terminal.
 * 
 * @param ent The entity to draw.
 * @param chars Buffer of characters to write to.
 * @param colors Buffer of colors to write to.
 * @param w Width of the terminal in characters.
 * @param h Height of the terminal in characters.
 */
void termDrawEntity(
  const entity_t *ent,
  char_t *chars,
  termcolor_t *colors,
  const int32_t w,
  const int32_t h
);

/**
 * Draw the UI to the terminal.
 * 
 * @param chars Buffer of characters to write to.
 * @param colors Buffer of colors to write to.
 * @param w Width of the terminal in characters.
 * @param h Height of the terminal in characters.
 */
void termDrawUI(
  char_t *chars,
  termcolor_t *colors,
  const int32_t w,
  const int32_t h
);