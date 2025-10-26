# Copyright (c) 2025 Dominic Masters
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

# Include directories
target_include_directories(microrpg PRIVATE ${CMAKE_CURRENT_LIST_DIR})

# Sources
target_sources(microrpg PRIVATE
  main.c
  game.c
  input.c
)

# Subdirs
add_subdirectory(entity)
add_subdirectory(scene)
add_subdirectory(world)

add_subdirectory(term)