#pragma once

#include <cstdio>
#include <string>
#ifndef CORE_LOGGER_NAME
#define CORE_LOGGER_NAME "unknown"
#endif

#ifndef CLI_LOGGER_NAME
#define CLI_LOGGER_NAME "unknown"
#endif

#include <spdlog/spdlog.h>

#ifndef LOG_ERRORS_ONLY
// Core
#define CORE_TRACE(...)                                               \
  do {                                                                \
    auto _lg = ::spdlog::get(CORE_LOGGER_NAME);                       \
    if (_lg) {                                                        \
      _lg->trace(__VA_ARGS__);                                        \
    }                                                                 \
    auto _fl = ::spdlog::get(std::string(CORE_LOGGER_NAME) + "_log"); \
    if (_fl) {                                                        \
      _fl->trace(__VA_ARGS__);                                        \
    }                                                                 \
  } while (0)

#define CORE_DEBUG(...)                                               \
  do {                                                                \
    auto _lg = ::spdlog::get(CORE_LOGGER_NAME);                       \
    if (_lg) {                                                        \
      _lg->debug(__VA_ARGS__);                                        \
    }                                                                 \
    auto _fl = ::spdlog::get(std::string(CORE_LOGGER_NAME) + "_log"); \
    if (_fl) {                                                        \
      _fl->debug(__VA_ARGS__);                                        \
    }                                                                 \
  } while (0)

#define CORE_INFO(...)                                                \
  do {                                                                \
    auto _lg = ::spdlog::get(CORE_LOGGER_NAME);                       \
    if (_lg) {                                                        \
      _lg->info(__VA_ARGS__);                                         \
    }                                                                 \
    auto _fl = ::spdlog::get(std::string(CORE_LOGGER_NAME) + "_log"); \
    if (_fl) {                                                        \
      _fl->info(__VA_ARGS__);                                         \
    }                                                                 \
  } while (0)

#define CORE_WARN(...)                                                \
  do {                                                                \
    auto _lg = ::spdlog::get(CORE_LOGGER_NAME);                       \
    if (_lg) {                                                        \
      _lg->warn(__VA_ARGS__);                                         \
    }                                                                 \
    auto _fl = ::spdlog::get(std::string(CORE_LOGGER_NAME) + "_log"); \
    if (_fl) {                                                        \
      _fl->warn(__VA_ARGS__);                                         \
    }                                                                 \
  } while (0)

#else
#define CORE_TRACE(...) (void)0
#define CORE_DEBUG(...) (void)0
#define CORE_INFO(...) (void)0
#define CORE_WARN(...) (void)0
#endif

#define CORE_ERROR(...)                                               \
  do {                                                                \
    auto _lg = ::spdlog::get(CORE_LOGGER_NAME);                       \
    if (_lg) {                                                        \
      _lg->error(__VA_ARGS__);                                        \
    }                                                                 \
    auto _fl = ::spdlog::get(std::string(CORE_LOGGER_NAME) + "_log"); \
    if (_fl) {                                                        \
      _fl->error(__VA_ARGS__);                                        \
    }                                                                 \
  } while (0)

#define CORE_FATAL(...)                                               \
  do {                                                                \
    auto _lg = ::spdlog::get(CORE_LOGGER_NAME);                       \
    if (_lg) {                                                        \
      _lg->critical(__VA_ARGS__);                                     \
    }                                                                 \
    auto _fl = ::spdlog::get(std::string(CORE_LOGGER_NAME) + "_log"); \
    if (_fl) {                                                        \
      _fl->critical(__VA_ARGS__);                                     \
    }                                                                 \
  } while (0)

// CLI
#define CLI_TRACE(...)                                               \
  do {                                                               \
    auto _lg = ::spdlog::get(CLI_LOGGER_NAME);                       \
    if (_lg) {                                                       \
      _lg->trace(__VA_ARGS__);                                       \
    }                                                                \
    auto _fl = ::spdlog::get(std::string(CLI_LOGGER_NAME) + "_log"); \
    if (_fl) {                                                       \
      _fl->trace(__VA_ARGS__);                                       \
    }                                                                \
  } while (0)

#define CLI_INFO(...)                                                \
  do {                                                               \
    auto _lg = ::spdlog::get(CLI_LOGGER_NAME);                       \
    if (_lg) {                                                       \
      _lg->info(__VA_ARGS__);                                        \
    }                                                                \
    auto _fl = ::spdlog::get(std::string(CLI_LOGGER_NAME) + "_log"); \
    if (_fl) {                                                       \
      _fl->info(__VA_ARGS__);                                        \
    }                                                                \
  } while (0)

#define CLI_DEBUG(...)                                               \
  do {                                                               \
    auto _lg = ::spdlog::get(CLI_LOGGER_NAME);                       \
    if (_lg) {                                                       \
      _lg->debug(__VA_ARGS__);                                       \
    }                                                                \
    auto _fl = ::spdlog::get(std::string(CLI_LOGGER_NAME) + "_log"); \
    if (_fl) {                                                       \
      _fl->debug(__VA_ARGS__);                                       \
    }                                                                \
  } while (0)

#define CLI_ERROR(...)                                               \
  do {                                                               \
    auto _lg = ::spdlog::get(CLI_LOGGER_NAME);                       \
    if (_lg) {                                                       \
      _lg->error(__VA_ARGS__);                                       \
    }                                                                \
    auto _fl = ::spdlog::get(std::string(CLI_LOGGER_NAME) + "_log"); \
    if (_fl) {                                                       \
      _fl->error(__VA_ARGS__);                                       \
    }                                                                \
  } while (0)
