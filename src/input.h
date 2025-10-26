/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"

#define INPUT_ACTION_UP (1 << 0)
#define INPUT_ACTION_DOWN (1 << 1)
#define INPUT_ACTION_LEFT (1 << 2)
#define INPUT_ACTION_RIGHT (1 << 3)
#define INPUT_ACTION_A (1 << 4)
#define INPUT_ACTION_B (1 << 5)
#define INPUT_ACTION_START (1 << 6)
#define INPUT_ACTION_SELECT (1 << 7)

/**
 * Check if an input action is currently held down.
 * 
 * @param action The action to check.
 * @return true if the action is held down, false otherwise.
 */
bool_t inputDown(const uint8_t action);

/**
 * Check if an input action is not currently held down.
 * 
 * @param action The action to check.
 * @return true if the action is not held down, false otherwise.
 */
bool_t inputUp(const uint8_t action);

/**
 * Check if an input action was held down in the previous tick.
 * 
 * @param action The action to check.
 * @return true if the action was down last tick, false otherwise.
 */
bool_t inputWasDown(const uint8_t action);

/**
 * Check if an input action was not held down in the previous tick.
 * 
 * @param action The action to check.
 * @return true if the action was up last tick, false otherwise.
 */
bool_t inputWasUp(const uint8_t action);

/**
 * Check if an input action was just pressed this tick.
 * 
 * @param action The action to check.
 * @return true if the action was just pressed, false otherwise.
 */
bool_t inputPressed(const uint8_t action);

/**
 * Check if an input action was just released this tick.
 * 
 * @param action The action to check.
 * @return true if the action was just released, false otherwise.
 */
bool_t inputReleased(const uint8_t action);