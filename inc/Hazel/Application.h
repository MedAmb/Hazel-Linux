#pragma once

#include "STLPCH.h"
#include "Hazel/Event/Event.h"
#include "Hazel/Event/KeyEvent.h"
#include "Hazel/Event/ApplicationEvent.h"
#include "Window.h"

namespace Hazel
{
    class Application
    {
    public:
        Application();
        void run(void);

        void onEvent(event& e);
        virtual ~Application();
    private:
        bool onWindowClose(windowCloseEvent& e);
        std::unique_ptr<window> m_Window;
        bool m_Running = true;
    };

    // To be defined in client 
    Application * createApplication();
}
