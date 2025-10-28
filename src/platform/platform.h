/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"

#define PLATFORM_OK 0
#define PLATFORM_EXIT 1
#define PLATFORM_ERROR 2

/**
 * Initialize the platform-specific subsystem.
 * 
 * @return 0 on success, non-zero on failure.
 */
uint8_t platformInit(void);

/**
 * Update the platform-specific subsystem.
 * 
 * @return 0 to continue, 1 to exit, anything else for error.
 */
uint8_t platformUpdate(void);

/**
 * Render the platform-specific subsystem.
 */
void platformDraw(void);

/**
 * Dispose of the platform-specific subsystem.
 */
void platformDispose(void);