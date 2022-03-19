#pragma once

extern Hazel::Application * Hazel::createApplication();

int main(int argc, char ** argv)
{
    auto ClientApp = Hazel::createApplication();
    ClientApp->run();
    delete ClientApp;
}