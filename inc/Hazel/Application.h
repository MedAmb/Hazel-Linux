#pragma once

#include "STLPCH.h"
#include "Hazel/Event/Event.h"
#include "Hazel/Event/KeyEvent.h"
#include "Hazel/Event/ApplicationEvent.h"

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
