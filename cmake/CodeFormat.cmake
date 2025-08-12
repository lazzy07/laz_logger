option(ENABLE_CLANG_TIDY "Run clang-tidy during builds" ON)

# --- clang-tidy integration ---
if(ENABLE_CLANG_TIDY)
message(STATUS "Clang tidy: STARTED")
find_program(CLANG_TIDY_EXE NAMES clang-tidy)
  if(CLANG_TIDY_EXE)
  # Runs tidy on each C++ file when it compiles
  set(CMAKE_CXX_CLANG_TIDY
  ${CLANG_TIDY_EXE};
  -p=${CMAKE_BINARY_DIR};
  --quiet
  -warnings-as-errors=*
  )
  else()
    message(STATUS "WARNING: Clang tidy: Not found, recommended if you want to contribute to the project")
  endif()
message(STATUS "Clang tidy: FINISHED")
endif()

# --- clang-format integration (repo-wide) ---
find_program(CLANG_FORMAT_EXE NAMES clang-format clang-format-18 clang-format-17)
if(CLANG_FORMAT_EXE)
  # Collect files to format (adjust paths/extensions as needed)
  file(GLOB_RECURSE ALL_LOGGER_CXX_FILES CONFIGURE_DEPENDS
       ${CMAKE_SOURCE_DIR}/src/*.[ch] ${CMAKE_SOURCE_DIR}/src/*.[ch]pp ${CMAKE_SOURCE_DIR}/src/*.cc
       ${CMAKE_SOURCE_DIR}/include/*.[ch] ${CMAKE_SOURCE_DIR}/include/*.[ch]pp
       ${CMAKE_SOURCE_DIR}/core/*.[ch]pp ${CMAKE_SOURCE_DIR}/cli/*.[ch]pp
       ${CMAKE_SOURCE_DIR}/*.[ch]pp
       ${CMAKE_SOURCE_DIR}/**/*.cu ${CMAKE_SOURCE_DIR}/**/*.cuh)

  # Remove vendor/ and generated code
  list(FILTER ALL_LOGGER_CXX_FILES EXCLUDE REGEX ".*/vendor/.*")
  list(FILTER ALL_LOGGER_CXX_FILES EXCLUDE REGEX ".*/generated/.*")

  message("Formatting: ${ALL_CXX_FILES}")

  if(NOT TARGET format)
    add_custom_target(format
      COMMAND ${CLANG_FORMAT_EXE} -i -style=file ${ALL_CXX_FILES}
      COMMENT "clang-format (repo-wide)" VERBATIM)
  endif()

  if(NOT TARGET format-check)
    add_custom_target(format-check
      COMMAND ${CLANG_FORMAT_EXE} --dry-run --Werror -style=file ${ALL_LOGGER_CXX_FILES}
      COMMENT "clang-format check (repo-wide)" VERBATIM)
  endif()
else()
  message(STATUS "clang-format not found; 'format' targets will not be available.")
endif()