#pragma once

#include <memory>
#include <spdlog/spdlog.h>

#include <filesystem>

namespace LazLogger{
  enum class LOGLEVEL{
    TRACE,
    INFO,
    WARN,
    ERR,
    FATAL
  };

  struct LoggerSpec { std::string name; std::filesystem::path file; };
  struct LoggerInit { LoggerSpec core; LoggerSpec cli; };

  class LoggerManager{
    public:
      void Initialize(const LoggerInit& opts);
      void Terminate();

      void SetCliLoggerLevel(LOGLEVEL loggerLevel);
      void SetCoreLoggerLevel(LOGLEVEL loggerLevel);

    public:
      std::shared_ptr<spdlog::logger> m_CoreLogger;
      std::shared_ptr<spdlog::logger> m_CoreFileLogger;
      std::shared_ptr<spdlog::logger> m_CliLogger;
      std::shared_ptr<spdlog::logger> m_CliFileLogger;
  };
}