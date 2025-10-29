# Copyright (c) 2025 Dominic Masters
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

# Libraries
find_package(Curses REQUIRED)

target_link_libraries(microrpg PRIVATE
  ${CURSES_LIBRARIES}
)
target_include_directories(microrpg PRIVATE
  ${CURSES_INCLUDE_DIR}
)
target_link_libraries(microrpg PRIVATE
  ${CURSES_LIBRARIES}
)

# Sources
target_sources(microrpg PRIVATE
  inputterm.c
  platform.c
  termtty.c
)

# Compiler flags
target_compile_definitions(microrpg PRIVATE
  RPG_TTY=1
)