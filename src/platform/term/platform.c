/**
 * Copyright (c) 2025 Dominic Masters
 * 
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */

#include "platform/platform.h"
#include "platform/term/term.h"

void platformInit() {
  termInit();
}

void platformUpdate() {
  termUpdate();
}

void platformDraw() {
  termDraw();
}

void platformDispose() {
  termDispose();
}