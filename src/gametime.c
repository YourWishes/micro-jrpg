/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "time.h"
#include "game.h"

void gameTimeTick() {
  GAME.time.ticks++;
  
  if(GAME.time.ticks >= GAME_TIME_TICKS_PER_SECOND) {
    GAME.time.ticks = 0;
    GAME.time.seconds++;

    if(GAME.time.seconds >= GAME_TIME_SECONDS_PER_MINUTE) {
      GAME.time.seconds = 0;
      GAME.time.minutes++;

      if(GAME.time.minutes >= GAME_TIME_MINUTES_PER_HOUR) {
        GAME.time.minutes = 0;
        GAME.time.hours++;

        if(GAME.time.hours >= GAME_TIME_HOURS_PER_DAY) {
          GAME.time.hours = 0;
          GAME.time.days++;

          if(GAME.time.days >= GAME_TIME_DAYS_MAX) {
            GAME.time.days = 0;
            // Roll over occured.
          }
        }
      }
    }
  }
}