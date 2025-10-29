# Copyright (c) 2025 Dominic Masters
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

if(NOT DEFINED PLATFORM)
    set(PLATFORM "raylib" CACHE STRING "Select the platform to build for (options: raylib, term, tty)")
endif()

if(PLATFORM STREQUAL "tty")
  add_subdirectory(term)
  add_subdirectory(tty)
elseif(PLATFORM STREQUAL "raylib")
  add_subdirectory(raylib)
  add_subdirectory(term)
else()
  message(FATAL_ERROR "Unknown PLATFORM: ${PLATFORM}.")
endif()