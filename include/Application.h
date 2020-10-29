//
// Created by Andrew Knee on 10/28/2020.
//

#ifndef CLOCKWORKENGINE_APPLICATION_H
#define CLOCKWORKENGINE_APPLICATION_H

#include "Defines.h"
#include "Manager.h"
#include "Config.h"
#include <GLFW/glfw3.h>

namespace ClockworkEngine{
    class Application{
    public:
        static Application* getInstance();
    private:
        Application();
        ~Application();

        static Application* instance;

        Manager *manager;
        GLFWwindow *window;
        Config mainConfig = Config({"screenWidth", "screenHeight", "sensitivity", "fov"});
    };
}

#endif //CLOCKWORKENGINE_APPLICATION_H
