# Copyright (c) 2025 Dominic Masters
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

# Sources
target_sources(microrpg PRIVATE
  term.c
  termoverworld.c
)

# Compiler flags
target_compile_definitions(microrpg PRIVATE
  RPG_TERM=1
)