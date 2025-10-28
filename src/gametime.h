/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#pragma once
#include "microrpg.h"

#define GAME_TIME_TICKS_PER_SECOND 60
#define GAME_TIME_SECONDS_PER_MINUTE 60
#define GAME_TIME_MINUTES_PER_HOUR 60
#define GAME_TIME_HOURS_PER_DAY 24
#define GAME_TIME_DAYS_MAX 7

#define GAME_TIME_SUNDAY 0
#define GAME_TIME_MONDAY 1
#define GAME_TIME_TUESDAY 2
#define GAME_TIME_WEDNESDAY 3
#define GAME_TIME_THURSDAY 4
#define GAME_TIME_FRIDAY 5
#define GAME_TIME_SATURDAY 6

typedef struct gametime_s {
  uint8_t ticks;
  uint8_t seconds;
  uint8_t minutes;
  uint8_t hours;
  uint8_t days;
} gametime_t;

/**
 * Advance the game time by one tick.
 */
void gameTimeTick();