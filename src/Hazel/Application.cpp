#include "Application.h"
#include "Hazel/Log.h"
#include "Event/Event.h"
#include "Event/ApplicationEvent.h"

namespace Hazel
{
        #define BIND(x) std::bind(&Application::x, this, std::placeholders::_1)

        Application::Application()
        {
            m_Window = std::unique_ptr<window>(window::createWindow());
            m_Window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
        }

        void Application::run()
        {
            std::cout << "Starting the Hazel engine !!\n" << std::flush;
            while(m_Running)
            {
                m_Window->onUpdate();
            }
        }

        bool Application::onWindowClose(windowCloseEvent& e)
        {
            m_Running = false;
            return true;
        }

        void Application::onEvent(event& e)
        {
            HZ_CORE_INFO(e);
            eventDispatcher dispatcher(e);
            //std::function<bool(Hazel::onWindowClose) myFUnc;
            dispatcher.dispatch<windowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));
        }

        Application::~Application()
        {

        }
}