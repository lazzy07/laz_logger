# LAZ Logger for C++ projects

This project is created as a wrapper to `spdlog` library to easily integrate a logger into a `C++` project.

You first must initialize the `LoggerManager` using LoggerManager's `Initialize()` and by passing in the names/file paths for the logger.

Also, you must declare `compile definitions` for loggers: (Highly reccomended to do this in CMake if you need project-specific logger names).

```cmake
target_compile_definitions(my_core_lib PRIVATE
  CORE_LOGGER_NAME="\"MyCore\""
  CLI_LOGGER_NAME="\"MyCLI\""
)
```
