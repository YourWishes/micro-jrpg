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
list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(ASSETS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets" CACHE PATH "Path to the assets directory")
set(TOOLS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tools" CACHE PATH "Path to the tools directory")

# Executable
add_executable(microrpg)

# Tools
add_subdirectory(tools)

# Add sources
add_subdirectory(src)