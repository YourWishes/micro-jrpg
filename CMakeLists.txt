# Copyright (c) 2025 Dominic Masters
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

cmake_minimum_required(VERSION 3.13)
project(microrpg
  VERSION 0.1.0
  DESCRIPTION "A tiny JRPG game written in C"
  LANGUAGES C
)

set(CMAKE_C_STANDARD 99)

# Executable
add_executable(microrpg)

# Add sources
add_subdirectory(src)