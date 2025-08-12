#include <spdlog/spdlog.h>

#ifndef CORE_LOGGER_NAME
  #define CORE_LOGGER_NAME "unknown"
#endif

#ifndef CLI_LOGGER_NAME 
  #define CLI_LOGGER_NAME "unknown"
#endif

#ifndef LOG_ERRORS_ONLY 

// Core Logging functionality
#define CORE_TRACE(...) if (spdlog::get(CORE_LOGGER_NAME) != nullptr) {spdlog::get(CORE_LOGGER_NAME)->trace(__VA_ARGS__); spdlog::get(std::string(CORE_LOGGER_NAME) + "_log")->trace(__VA_ARGS__);}

#define CORE_DEBUG(...) if (spdlog::get(CORE_LOGGER_NAME) != nullptr) {spdlog::get(CORE_LOGGER_NAME)->debug(__VA_ARGS__); spdlog::get(std::string(CORE_LOGGER_NAME) + "_log")->debug(__VA_ARGS__);}

#define CORE_INFO(...) if (spdlog::get(CORE_LOGGER_NAME) != nullptr) {spdlog::get(CORE_LOGGER_NAME)->info(__VA_ARGS__); spdlog::get(std::string(CORE_LOGGER_NAME) + "_log")->info(__VA_ARGS__);}

#define CORE_WARN(...) if (spdlog::get(CORE_LOGGER_NAME) != nullptr) {spdlog::get(CORE_LOGGER_NAME)->warn(__VA_ARGS__); spdlog::get(std::string(CORE_LOGGER_NAME) + "_log")->warn(__VA_ARGS__);}

#else
#define CORE_TRACE(...) (void)0
#define CORE_DEBUG(...) (void)0
#define CORE_INFO(...) (void)0
#define CORE_WARN(...) (void)0
#endif

#define CORE_ERROR(...) if (spdlog::get(CORE_LOGGER_NAME) != nullptr) {spdlog::get(CORE_LOGGER_NAME)->error(__VA_ARGS__); spdlog::get(std::string(CORE_LOGGER_NAME) + "_log")->error(__VA_ARGS__);}

#define CORE_FATAL(...) if (spdlog::get(CORE_LOGGER_NAME) != nullptr) {spdlog::get(CORE_LOGGER_NAME)->critical(__VA_ARGS__); spdlog::get(std::string(CORE_LOGGER_NAME) + "_log")->critical(__VA_ARGS__);}



//CLI Logging functionality
#define CLI_TRACE(...) if (spdlog::get(CLI_LOGGER_NAME) != nullptr) {spdlog::get(CLI_LOGGER_NAME)->trace(__VA_ARGS__); spdlog::get(std::string(CLI_LOGGER_NAME) + "_log")->trace(__VA_ARGS__);}

#define CLI_INFO(...) if (spdlog::get(CLI_LOGGER_NAME) != nullptr) {spdlog::get(CLI_LOGGER_NAME)->info(__VA_ARGS__); spdlog::get(std::string(CLI_LOGGER_NAME) + "_log")->info(__VA_ARGS__);}

#define CLI_DEBUG(...) if (spdlog::get(CLI_LOGGER_NAME) != nullptr) {spdlog::get(CLI_LOGGER_NAME)->debug(__VA_ARGS__); spdlog::get(std::string(CLI_LOGGER_NAME) + "_log")->debug(__VA_ARGS__);}

#define CLI_ERROR(...) if (spdlog::get(CLI_LOGGER_NAME) != nullptr) {spdlog::get(CLI_LOGGER_NAME)->trace(__VA_ARGS__); spdlog::get(std::string(CLI_LOGGER_NAME) + "_log")->trace(__VA_ARGS__);}