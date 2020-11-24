//
// Created by Andrew Knee on 10/24/2020.
//

#ifndef CLOCKWORKENGINE_INPUT_H
#define CLOCKWORKENGINE_INPUT_H

#include <GLFW/glfw3.h>
#include <vector>
#include <map>
#include <algorithm>

namespace ClockworkEngine {

    class Input {
    public:
        Input(std::vector<int> keysToMonitor, std::vector<int> mouseButtonsToMonitor);

        ~Input();

        bool getIsKeyDown(int key);

        std::pair<double, double> getMousePos();

        std::pair<double, double> getMouseOffset();

        std::pair<double, double> getScroll();

        bool getIsMouseButtonDown(int key);

        static void setUpInputs(GLFWwindow *window);

        static void setUpMouseInputs(GLFWwindow *window);

        static void setUpMouseButton(GLFWwindow *window);

        static void setUpScroll(GLFWwindow *window);

    private:
        static void callBack(GLFWwindow *window, int key, int scancode, int action, int mods);

        static void mouseCallBack(GLFWwindow *window, double xpos, double ypos);

        static void mouseButtonCallBack(GLFWwindow *window, int button, int action, int mods);

        static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

        void setIsKeyDown(int key, bool isDown);

        void setMouseButtonIsDown(int key, bool isDown);

        static std::vector<Input *> _instances;
        std::map<int, bool> _keys;
        std::map<int, bool> _mouseButtons;
        bool _isEnabled;

        bool firstMouse = true;
        double lastX = 0, lastY = 0;
        double xOffset = 0, yOffset = 0;
        double xScroll = 0, yScroll = 0;
    };
}
#endif //CLOCKWORKENGINE_INPUT_H