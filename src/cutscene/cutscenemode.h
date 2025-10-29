/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"

// Mode 0, Assume no cutscene is active.
#define CUTSCENE_MODE_NONE 0

// Mode 1, assume that the cutscene is controlling all gameplay (full freeze).
#define CUTSCENE_MODE_FULL_FREEZE 1

// Mode 2, assume that the cutscene is simply stopping regular player input.
#define CUTSCENE_MODE_INPUT_FREEZE 2

// Mode 3, assume that the cutscene is not affecting gameplay directly.
#define CUTSCENE_MODE_GAMEPLAY 3

// Default mode for all cutscenes.
#define CUTSCENE_MODE_INITIAL CUTSCENE_MODE_INPUT_FREEZE

typedef uint8_t cutscenemode_t;

/**
 * Check if input is allowed in the current cutscene mode.
 * 
 * @return true if input is allowed, false otherwise.
 */
bool_t cutsceneModeIsInputAllowed();