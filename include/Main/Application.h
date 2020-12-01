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
        static std::shared_ptr<Application> getInstance();

        static std::shared_ptr<Application> initialize(bool *worked);

        GLFWwindow *getWindow();

        std::shared_ptr<Manager> getManager();

        std::shared_ptr<RendererAPI> getRendererAPI();

        ~Application();

    private:
        explicit Application(bool *worked);

        static std::shared_ptr<Application> instance;

        std::shared_ptr<Manager> manager;
        GLFWwindow *window;
        Config mainConfig = Config({"screenWidth", "screenHeight", "sensitivity", "fov", "renderingAPI"}, "con.fig");
        std::shared_ptr<RendererAPI> rendererAPI;
    };
}

#endif //CLOCKWORKENGINE_APPLICATION_H
