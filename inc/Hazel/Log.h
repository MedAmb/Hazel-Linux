#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
#include "STLPCH.h"


namespace Hazel
{
    class Log
    {
    private:
        static std::shared_ptr<spdlog::logger> s_coreLogger;
        static std::shared_ptr<spdlog::logger> s_clientLogger;

    public:
        static void initLogger();
        static inline std::shared_ptr<spdlog::logger>& getCoreLogger(void) { return s_coreLogger; }
        static inline std::shared_ptr<spdlog::logger>& getClientLogger(void) { return s_clientLogger; }
    };
}

#ifdef DEBUG
#define HZ_CORE_ERROR(format) ::Hazel::Log::getCoreLogger()->error(format);
#define HZ_CORE_WARN(format) ::Hazel::Log::getCoreLogger()->warn(format);
#define HZ_CORE_INFO(format) ::Hazel::Log::getCoreLogger()->info(format);
#define HZ_APP_ERROR(format) ::Hazel::Log::getClientLogger()->error(format);
#define HZ_APP_WARN(format) ::Hazel::Log::getClientLogger()->warn(format);
#define HZ_APP_INFO(format) ::Hazel::Log::getClientLogger()->info(format);
#else
#define HZ_CORE_ERROR(format)
#define HZ_CORE_WARN(format)
#define HZ_CORE_INFO(format)
#define HZ_APP_ERROR(format)
#define HZ_APP_WARN(format)
#define HZ_APP_INFO(format)
#endif