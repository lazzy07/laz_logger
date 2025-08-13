set(SPDLOG_VER "1.15.3")
set(SPDLOG_TAG "v${SPDLOG_VER}")
set(SPDLOG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog-${SPDLOG_VER}")

if(NOT EXISTS "${SPDLOG_DIR}/CMakeLists.txt")
  file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/vendor")
  set(_zip "${CMAKE_BINARY_DIR}/spdlog-${SPDLOG_TAG}.zip")
  file(DOWNLOAD
    "https://github.com/gabime/spdlog/archive/refs/tags/${SPDLOG_TAG}.zip"
    "${_zip}" SHOW_PROGRESS TLS_VERIFY ON)
  execute_process(COMMAND ${CMAKE_COMMAND} -E tar xvf "${_zip}"
                  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}" RESULT_VARIABLE rc)
  if(NOT rc EQUAL 0)
    message(FATAL_ERROR "Failed to extract laz_logger ${SPDLOG_TAG}")
  endif()
  file(RENAME "${CMAKE_BINARY_DIR}/spdlog-${SPDLOG_VER}" "${SPDLOG_DIR}")
endif()

set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
add_subdirectory("${SPDLOG_DIR}" EXCLUDE_FROM_ALL)

list(FILTER ALL_CXX_FILES EXCLUDE REGEX ".*/vendor/spdlog-1\\.15\\.3/.*")