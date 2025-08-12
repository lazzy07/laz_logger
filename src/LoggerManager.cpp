#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <iostream>
#include <lazlogger/LoggerManager.hpp>

void LazLogger::LoggerManager::Initialize(const LoggerInit &opts) {
  constexpr int kMaxSize = 1048576;
  constexpr int kMaxFiles = 3;
  if (m_CliLogger) {
    return;
  }

  namespace fs = std::filesystem;
  try {
    // Ensure log directories exist
    fs::create_directories(fs::path(opts.core.file).parent_path());
    fs::create_directories(fs::path(opts.cli.file).parent_path());
  } catch (const fs::filesystem_error &e) {
    std::cerr << "Logger failed to create directories: " << e.what() << "\n";
    return;
  }

  std::string pattern_with_info = "%^%n [%l] (%Y:%m:%d %H:%M:%S.%e)%$: %v";

  m_CliLogger = spdlog::stdout_color_mt(opts.cli.name);
  std::string cliFileLoggerName = std::string(opts.cli.name) + "_log";
  m_CliFileLogger =
      spdlog::rotating_logger_mt(cliFileLoggerName, opts.cli.file, kMaxSize, kMaxFiles);
  m_CoreLogger = spdlog::stdout_color_mt(opts.core.name);
  std::string coreFileLoggerName = std::string(opts.core.name) + "_log";
  m_CoreFileLogger =
      spdlog::rotating_logger_mt(coreFileLoggerName, opts.core.file, kMaxSize, kMaxFiles);

  // Setting up logger patterns
  m_CliFileLogger->set_pattern(pattern_with_info);
  m_CoreLogger->set_pattern(pattern_with_info);
  m_CoreFileLogger->set_pattern(pattern_with_info);
  // Cli logger just need to print the message
  m_CliLogger->set_pattern("%^%v%$");

  SetCoreLoggerLevel(LOGLEVEL::TRACE);
  SetCliLoggerLevel(LOGLEVEL::TRACE);
}

void LazLogger::LoggerManager::Terminate() {
  spdlog::shutdown();

  if (m_CliFileLogger) {
    m_CoreLogger->trace("CLI file logger Terminated");
    m_CoreFileLogger->trace("CLI file logger Terminated");

    m_CliFileLogger->flush();
    spdlog::drop(m_CliFileLogger->name());
    m_CliFileLogger.reset();
  }

  if (m_CliLogger) {
    m_CoreLogger->trace("CLI logger Terminated");
    m_CoreFileLogger->trace("CLI logger Terminated");

    m_CliLogger->flush();
    spdlog::drop(m_CliLogger->name());
    m_CliLogger.reset();
  }

  if (m_CoreFileLogger) {
    m_CoreLogger->trace("Core file logger Terminated");
    m_CoreFileLogger->trace("Core file logger Terminated");

    m_CoreFileLogger->flush();
    spdlog::drop(m_CoreFileLogger->name());
    m_CoreFileLogger.reset();
  }

  if (m_CoreLogger) {
    m_CoreLogger->trace("Core logger Terminated");
    m_CoreLogger->flush();
    spdlog::drop(m_CoreLogger->name());
    m_CoreLogger.reset();
  }
}

void LazLogger::LoggerManager::SetCliLoggerLevel(LOGLEVEL loggerLevel) {
  switch (loggerLevel) {
    case LOGLEVEL::TRACE:
      m_CliLogger->set_level(spdlog::level::trace);
      m_CliFileLogger->set_level(spdlog::level::trace);
      break;

    case LOGLEVEL::INFO:
      m_CliLogger->set_level(spdlog::level::info);
      m_CliFileLogger->set_level(spdlog::level::info);
      break;

    case LOGLEVEL::WARN:
      m_CliLogger->set_level(spdlog::level::warn);
      m_CliFileLogger->set_level(spdlog::level::warn);
      break;

    case LOGLEVEL::ERR:
      m_CliLogger->set_level(spdlog::level::err);
      m_CliFileLogger->set_level(spdlog::level::err);
      break;

    case LOGLEVEL::FATAL:
      m_CliLogger->set_level(spdlog::level::critical);
      m_CliFileLogger->set_level(spdlog::level::critical);
      break;
  }
}

void LazLogger::LoggerManager::SetCoreLoggerLevel(LOGLEVEL loggerLevel) {
  switch (loggerLevel) {
    case LOGLEVEL::TRACE:
      m_CoreLogger->set_level(spdlog::level::trace);
      m_CoreFileLogger->set_level(spdlog::level::trace);
      break;

    case LOGLEVEL::INFO:
      m_CoreLogger->set_level(spdlog::level::info);
      m_CoreFileLogger->set_level(spdlog::level::info);
      break;

    case LOGLEVEL::WARN:
      m_CoreLogger->set_level(spdlog::level::warn);
      m_CoreFileLogger->set_level(spdlog::level::warn);
      break;

    case LOGLEVEL::ERR:
      m_CoreLogger->set_level(spdlog::level::err);
      m_CoreFileLogger->set_level(spdlog::level::err);
      break;

    case LOGLEVEL::FATAL:
      m_CoreLogger->set_level(spdlog::level::critical);
      m_CoreFileLogger->set_level(spdlog::level::critical);
      break;
  }
}