/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"

/**
 * Initialize the platform-specific subsystem.
 */
void platformInit(void);

/**
 * Update the platform-specific subsystem.
 */
void platformUpdate(void);

/**
 * Render the platform-specific subsystem.
 */
void platformDraw(void);

/**
 * Dispose of the platform-specific subsystem.
 */
void platformDispose(void);