
#include "STLPCH.h"

#include "Event/Event.h"
#include "Hazel/Core.h"

namespace Hazel
{
    struct windowProps
    {
        std::string title;
        unsigned int height;
        unsigned int width;

        windowProps(const std::string& p_Title = "Hazel Engine", 
                    unsigned int p_Height = 720,
                    unsigned int p_Width = 1280)
        :title(p_Title), height(p_Height), width(p_Width)
        {
        
        }
    };

    class window
    {
        public:
            using eventCallbackFn = std::function<void(event&)>;

            virtual ~window() {}

            virtual void onUpdate() = 0;

            virtual unsigned int getWidth() const = 0;
            virtual unsigned int getHeight() const = 0;

            virtual void setEventCallback(const eventCallbackFn& callback) = 0;
            virtual void setVSync(bool enable) = 0;
            virtual bool isVSync(void) const = 0;

            static window* createWindow(const windowProps& props = windowProps());

    };
}