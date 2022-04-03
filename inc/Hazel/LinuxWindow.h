#pragma once

#include "Window.h"

#include "GLFW/glfw3.h"

namespace Hazel
{
    class linuxWindow : public window
    {
    public:
        linuxWindow(const windowProps &props);
        virtual ~linuxWindow();

        void onUpdate() override;

        unsigned int getWidth() const override { return m_Data.width; }
        unsigned int getHeight() const override { return m_Data.height; }

        void setEventCallback(const eventCallbackFn &callback) { m_Data.callback = callback; }
        void setVSync(bool enabled) override;
        bool isVSync(void) const override;

    private:
        virtual void init(const windowProps &props);
        virtual void shutDown();
    private:
        GLFWwindow * m_Window;

        struct windowData
        {
            std::string title;
            unsigned int width, height;
            bool vSync;
            eventCallbackFn callback;
        };

        windowData m_Data;
    };
}
