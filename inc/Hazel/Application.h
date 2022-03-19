#pragma once

#include  <iostream>

namespace Hazel
{
    class Application
    {
    public:
        Application();
        void run(void);
        virtual ~Application();
    };


    Application * createApplication();
}
