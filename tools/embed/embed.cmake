# Copyright (c) 2025 Dominic Masters
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

# We are passed -DINPUT_FILE (absolute) and -DOUTPUT_FILE (absolute) and -DC_VAR_NAME (name of the C variable to hold the data)

file(READ "${INPUT_FILE}" RAW_DATA HEX)
string(LENGTH "${RAW_DATA}" DATA_LENGTH)
set(OUTPUT_CONTENT "/* This file is auto-generated. Do not edit directly. */\n")
set(OUTPUT_CONTENT "${OUTPUT_CONTENT}#pragma once\n#include \"microrpg.h\"\n\n")
set(OUTPUT_CONTENT "${OUTPUT_CONTENT}static const uint8_t ${C_VAR_NAME}_DATA[] = {\n  ")
set(INDEX 0)
while(INDEX LESS DATA_LENGTH)
  string(SUBSTRING "${RAW_DATA}" ${INDEX} 2 BYTE)
  set(OUTPUT_CONTENT "${OUTPUT_CONTENT}0x${BYTE}, ")
  math(EXPR INDEX "${INDEX} + 2")
endwhile()
set(OUTPUT_CONTENT "${OUTPUT_CONTENT}\n};\n\n")
set(OUTPUT_CONTENT "${OUTPUT_CONTENT}#define ${C_VAR_NAME}_SIZE ${DATA_LENGTH}u\n")
file(WRITE "${OUTPUT_FILE}" "${OUTPUT_CONTENT}")