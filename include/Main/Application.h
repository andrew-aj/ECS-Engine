//
// Created by Andrew Knee on 10/28/2020.
//

#ifndef CLOCKWORKENGINE_APPLICATION_H
#define CLOCKWORKENGINE_APPLICATION_H

#include "Defines.h"
#include "Manager.h"
#include "Config.h"
#include "Rendering/RendererAPI.h"
#include <GLFW/glfw3.h>

namespace ClockworkEngine {
    class Application {
    public:
        static Application *getInstance();

        static Application *initialize(bool *worked);

        GLFWwindow *getWindow();

        Manager *getManager();

        RendererAPI *getRendererAPI();

    private:
        Application(bool *worked);

        ~Application();

        static Application *instance;

        Manager *manager;
        GLFWwindow *window;
        Config mainConfig = Config({"screenWidth", "screenHeight", "sensitivity", "fov", "renderingAPI"}, "con.fig");
        RendererAPI *rendererAPI;
    };
}

#endif //CLOCKWORKENGINE_APPLICATION_H
