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
#define HZ_CORE_ERROR(...) ::Hazel::Log::getCoreLogger()->error(__VA_ARGS__ );
#define HZ_CORE_WARN(...) ::Hazel::Log::getCoreLogger()->warn(__VA_ARGS__ );
#define HZ_CORE_INFO(...) ::Hazel::Log::getCoreLogger()->info(__VA_ARGS__ );
#define HZ_APP_ERROR(...) ::Hazel::Log::getClientLogger()->error(__VA_ARGS__ );
#define HZ_APP_WARN(...) ::Hazel::Log::getClientLogger()->warn(__VA_ARGS__ );
#define HZ_APP_INFO(...) ::Hazel::Log::getClientLogger()->info(__VA_ARGS__ );
#else
#define HZ_CORE_ERROR(...)
#define HZ_CORE_WARN(...)
#define HZ_CORE_INFO(...)
#define HZ_APP_ERROR(...)
#define HZ_APP_WARN(...)
#define HZ_APP_INFO(...)
#endif