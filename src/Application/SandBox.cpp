#include "Pub/Hazel.h"

class sandBox: public Hazel::Application
{
    public:
            sandBox()
        {

        }

        ~sandBox()
        {

        }
};


Hazel::Application * Hazel::createApplication()
{
    return new sandBox();
}