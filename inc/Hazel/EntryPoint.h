#pragma once

extern Hazel::Application * Hazel::createApplication();

int main(int argc, char **argv)
{
    Hazel::Log::initLogger();
    ::Hazel::Log::getCoreLogger()->error("hello");
    auto ClientApp = Hazel::createApplication();
    HZ_CORE_ERROR("HELLO FROM HAZEL");
    HZ_APP_WARN("HELLO FROM APP");
    ClientApp->run();
    delete ClientApp;
}