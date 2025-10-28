# Copyright (c) 2025 Dominic Masters
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

function(embed_file TARGET_NAME INPUT_FILE_ABS OUTPUT_FILE_HEADER C_VAR_NAME)
  set(OUTPUT_FILE_ABS "${CMAKE_BINARY_DIR}/generated_headers/${OUTPUT_FILE_HEADER}")

  # Create a custom target
  add_custom_target(
    "${INPUT_FILE}_embed"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/generated_headers"
    COMMAND ${CMAKE_COMMAND} -DINPUT_FILE="${INPUT_FILE_ABS}" -DOUTPUT_FILE="${OUTPUT_FILE_ABS}" -DC_VAR_NAME="${C_VAR_NAME}" -P "${TOOLS_DIR}/embed/embed.cmake"
    DEPENDS "${INPUT_FILE_ABS}"
  )

  # Add the generated header to the target's include directories
  target_include_directories(${TARGET_NAME} PRIVATE "${CMAKE_BINARY_DIR}/generated_headers")

  # Make the target depend on the custom target
  add_dependencies(${TARGET_NAME} "${INPUT_FILE}_embed")
endfunction()