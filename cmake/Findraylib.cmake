# Findraylib.cmake — minimal: system paths → FetchContent
# Exposes: raylib::raylib, raylib_FOUND

include_guard(GLOBAL)

set(_RAYLIB_TAG "5.5")
set(_RAYLIB_URL "https://github.com/raysan5/raylib/archive/refs/tags/${_RAYLIB_TAG}.tar.gz")
set(_RAYLIB_ROOT "")

# Try system install first
find_path(_RAYLIB_INCLUDE_DIR raylib.h
  HINTS "${_RAYLIB_ROOT}/include"
  PATHS /usr/include /usr/local/include
  PATH_SUFFIXES raylib
)
find_library(_RAYLIB_LIBRARY raylib
  HINTS "${_RAYLIB_ROOT}/lib" "${_RAYLIB_ROOT}/lib64"
  PATHS /usr/lib /usr/lib64 /usr/local/lib /usr/local/lib64
)

if (_RAYLIB_INCLUDE_DIR AND _RAYLIB_LIBRARY)
  add_library(raylib UNKNOWN IMPORTED)
  set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION "${_RAYLIB_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${_RAYLIB_INCLUDE_DIR}"
  )
else()
  include(FetchContent)

  # Fix CMP0135 warning
  if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
  endif()

  if (DEFINED FETCHCONTENT_SOURCE_DIR_RAYLIB AND
      NOT EXISTS "${FETCHCONTENT_SOURCE_DIR_RAYLIB}")
    unset(FETCHCONTENT_SOURCE_DIR_RAYLIB CACHE)
  endif()

  set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
  set(RAYLIB_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(RAYLIB_BUILD_GAMES OFF CACHE BOOL "" FORCE)

  FetchContent_Declare(raylib
    URL "${_RAYLIB_URL}"
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  )
  FetchContent_MakeAvailable(raylib)

  if (NOT TARGET raylib)
    message(FATAL_ERROR "raylib target not defined after fetch.")
  endif()
endif()

# Normalize exported target
if (NOT TARGET raylib::raylib)
  add_library(raylib::raylib ALIAS raylib)
endif()

set(raylib_FOUND TRUE)
