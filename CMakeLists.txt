cmake_minimum_required(VERSION 3.15)

# Enable or desable clang-tidy
option(ENABLE_CLANG_TIDY "Run clang-tidy during builds" ON)

project(laz_logger LANGUAGES C CXX)

# Cmake helper file-paths
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Only include formatting when laz_logger is the top-level project
if (CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  include(CodeFormat)
endif()
include(SpdLog)

file(
  GLOB_RECURSE 
  LOGGER_SRC_FILES 
  CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

message("File Glob: ${LOGGER_SRC_FILES}")

add_library(
  lazlogger SHARED
  ${LOGGER_SRC_FILES}
)

target_include_directories(
  lazlogger
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog-1.15.3/include"
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_definitions(lazlogger PUBLIC FMT_HEADER_ONLY)
# target_compile_definitions(lazlogger PUBLIC FMT_DEPRECATED)