//
// Created by Andrew Knee on 10/28/2020.
//

#ifndef CLOCKWORKENGINE_APPLICATION_H
#define CLOCKWORKENGINE_APPLICATION_H

#include "Defines.h"
#include "Manager.h"
#include <GLFW/glfw3.h>

namespace ClockworkEngine{
    class Application{
    public:
        Application();
        ~Application();
    private:
        Manager *manager;
        GLFWwindow *window;
    };
}

#endif //CLOCKWORKENGINE_APPLICATION_H
