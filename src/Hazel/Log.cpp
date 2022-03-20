#include "Hazel/Log.h"


namespace Hazel
{
    std::shared_ptr<spdlog::logger> Log::s_coreLogger;
    std::shared_ptr<spdlog::logger> Log::s_clientLogger;

    void Log::initLogger()
    {
        spdlog::set_pattern("%^[%T] %n:  %v%$");
        s_coreLogger = spdlog::stdout_color_mt("HAZEL");
        s_coreLogger->set_level(spdlog::level::trace);
        s_clientLogger = spdlog::stdout_color_mt("APP");
        s_coreLogger->set_level(spdlog::level::trace);
    }
}