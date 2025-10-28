# Copyright (c) 2025 Dominic Masters
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

# Libraries
find_package(raylib REQUIRED)

target_link_libraries(microrpg PRIVATE
  raylib::raylib
)

# Sources
target_sources(microrpg PRIVATE
  inputraylib.c
  termraylib.c
  platform.c
  font.c
)

# Embed resources
embed_file(microrpg "${ASSETS_DIR}/8x8ascii-darkrose/font.png" "assets/font.h" FONT)

# Compiler flags
target_compile_definitions(microrpg PRIVATE
  RPG_RAYLIB=1
)