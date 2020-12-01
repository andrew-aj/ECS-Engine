//
// Created by Andrew Knee on 10/28/2020.
//

#include "Main/Application.h"

namespace ClockworkEngine {
    std::shared_ptr<Application> Application::instance = nullptr;

    std::shared_ptr<Application> Application::getInstance() {
        return instance;
    }

    std::shared_ptr<Application> Application::initialize(bool *worked) {
        //Had to use this because std::make_shared didn't like private constructor
        //Not bad though because it's only called once when the application starts.
        instance = std::shared_ptr<Application>(new Application(worked));
        return instance;
    }

    Application::Application(bool *worked) {
        manager = std::make_shared<Manager>();
        auto conf = mainConfig.getConfig();
        int screenWidth = std::stoi(conf["screenWidth"]);
        int screenHeight = std::stoi(conf["screenHeight"]);
        rendererAPI = std::make_shared<RendererAPI>();

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
        instance.reset();
        glfwTerminate();
        manager.reset();
    }

    GLFWwindow *Application::getWindow() {
        return window;
    }

    std::shared_ptr<Manager> Application::getManager() {
        return manager;
    }

    std::shared_ptr<RendererAPI> Application::getRendererAPI() {
        return rendererAPI;
    }
}