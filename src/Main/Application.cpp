//
// Created by Andrew Knee on 10/28/2020.
//

#include "Main/Application.h"

namespace ClockworkEngine {
    Application *Application::instance = nullptr;

    Application *Application::getInstance() {
        return instance;
    }

    Application *Application::initialize(bool *worked) {
        instance = new Application(worked);
        return instance;
    }

    Application::Application(bool *worked) {
        manager = new Manager();
        auto conf = mainConfig.getConfig();
        int screenWidth = std::stoi(conf["screenWidth"]);
        int screenHeight = std::stoi(conf["screenHeight"]);
        rendererAPI = RendererAPI::createAPI(RendererAPI::stringToEnum(conf["renderingAPI"]));

        if (!glfwInit()) {
            *worked = false;
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        window = glfwCreateWindow(screenWidth, screenHeight, "ClockworkEngine", nullptr, nullptr);
        if (window == nullptr) {
            std::cout << "Failed create window context." << std::endl;
            glfwTerminate();
            *worked = false;
        }
        glfwMakeContextCurrent(window);
    }

    Application::~Application() {
        delete instance;
        glfwTerminate();
        delete manager;
    }

    GLFWwindow *Application::getWindow() {
        return window;
    }

    Manager *Application::getManager() {
        return manager;
    }

    RendererAPI *Application::getRendererAPI() {
        return rendererAPI;
    }
}