/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"

#define SCENE_INITIAL 0
#define SCENE_OVERWORLD 1

typedef uint8_t scene_t;

void sceneTick();