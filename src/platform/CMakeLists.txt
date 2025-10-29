# Copyright (c) 2025 Dominic Masters
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

if(NOT DEFINED RPG_PLATFORM)
    set(RPG_PLATFORM "raylib" CACHE STRING "Select the platform to build for")
endif()

if(RPG_PLATFORM STREQUAL "tty")
  add_subdirectory(term)
  add_subdirectory(tty)
elseif(RPG_PLATFORM STREQUAL "raylib")
  add_subdirectory(raylib)
  add_subdirectory(term)
else()
  message(FATAL_ERROR "Unknown RPG_PLATFORM: ${RPG_PLATFORM}.")
endif()