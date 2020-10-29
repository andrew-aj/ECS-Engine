//
// Created by Andrew Knee on 10/28/2020.
//

#include "Application.h"

namespace ClockworkEngine {
    Application *Application::instance = nullptr;

    Application *Application::getInstance() {
        if (instance == nullptr) {
            instance = new Application();
        }
        return instance;
    }

    Application::Application() {
        manager = new Manager();
        auto conf = mainConfig.getConfig();
        int screenWidth = std::stoi(conf["screenWidth"]);
        int screenHeight = std::stoi(conf["screenHeight"]);
        glfwInit();
        window = glfwCreateWindow(screenWidth, screenHeight, "ClockworkEngine", nullptr, nullptr);
    }

    Application::~Application() {
        delete instance;
    }
}