#include "STLPCH.h"

#include "LinuxWindow.h"
#include "Log.h"


#include "Event/ApplicationEvent.h"
#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"

namespace Hazel
{
    static bool s_GLFWinitialized = false;

    static void GLFWErrorCallback(int error, const char * description)
    {
        HZ_CORE_ERROR("GLFW ERROR error code : {0}, error description {1}", error, description);
    }

    window *window::createWindow(const windowProps &props)
    {
        return new linuxWindow(props);
    }

    linuxWindow::linuxWindow(const windowProps &props)
    {
        init(props);
    }

    linuxWindow::~linuxWindow()
    {
        shutDown();
    }

    void linuxWindow::init(const windowProps &props)
    {
        m_Data.title = props.title;
        m_Data.height = props.height;
        m_Data.width = props.width;

        HZ_CORE_INFO("Creating Window, name : {0}, height : {1}, width : {2}", m_Data.title, m_Data.height, m_Data.width);

        if (!s_GLFWinitialized)
        {
            // TODO : glfwTerminate on system shutdown
            int success = glfwInit();
            HZ_CORE_ASSERT(success, "Coulld not Initialize GLFW");
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWinitialized = true;
        }

        m_Window = glfwCreateWindow((int)m_Data.width, (int)m_Data.height, (const char *)m_Data.title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        setVSync(true);

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height)
                                  {
			windowData& data = *(windowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			windowResizeEvent event(width, height);
			data.callback(event); });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window)
                                   {
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);
            windowCloseEvent event;
            data.callback(event); });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
                                {
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    keyPressedEvent event(key, 0);
                    data.callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    keyReleasedEvent event(key);
                    data.callback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    keyPressedEvent event(key, 1);
                    data.callback(event);
                    break;
                }
            } });

        glfwSetCharCallback(m_Window, [](GLFWwindow *window, unsigned int keycode)
                            {
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

            keyTypedEvent event(keycode);
            data.callback(event); });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods)
                                   {
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    mouseButtonPressedEvent event(button);
                    data.callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    mouseButtonReleasedEvent event(button);
                    data.callback(event);
                    break;
                }
            } });

        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xOffset, double yOffset)
                              {
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

            mouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.callback(event); });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double xPos, double yPos)
                                 {
            windowData& data = *(windowData*)glfwGetWindowUserPointer(window);

            mouseMovedEvent event((float)xPos, (float)yPos);
            data.callback(event); });

    }

    void linuxWindow::shutDown()
    {
        glfwDestroyWindow(m_Window);
    }

    void linuxWindow::setVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.vSync = enabled;
    }

    bool linuxWindow::isVSync(void) const
    {
        return m_Data.vSync;
    }

    void linuxWindow::onUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }
}