#include "Application.h"
#include "Hazel/Log.h"

int boing(void);
namespace Hazel
{
        Application::Application()
        {

        }

        void Application::run()
        {
            std::cout << "Starting the Hazel engine !!\n" << std::flush;
            windowResizeEvent e(12, 50);
            if(e.isInCategory(eventCategoryInput))
            {
                HZ_CORE_INFO(e);
            }
            else
            {
                HZ_CORE_WARN(e);
            }
        }

        Application::~Application()
        {

        }
}