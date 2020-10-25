//
// Created by Andrew Knee on 10/24/2020.
//

#ifndef CLOCKWORKENGINE_INPUT_H
#define CLOCKWORKENGINE_INPUT_H

#include <GLFW/glfw3.h>
#include <vector>
#include <map>
#include <algorithm>

class Input {
public:
    Input(std::vector<int> keysToMonitor, std::vector<int> mouseButtonsToMonitor) : _isEnabled(true) {
        for (int key : keysToMonitor) {
            _keys[key] = false;
        }
        for (int key : mouseButtonsToMonitor) {
            _mouseButtons[key] = false;
        }
        _instances.push_back(this);
    }

    ~Input() {
        _instances.erase(std::remove(_instances.begin(), _instances.end(), this), _instances.end());
    }

    bool getIsKeyDown(int key) {
        bool result = false;
        if (_isEnabled) {
            auto it = _keys.find(key);
            if (it != _keys.end()) {
                result = _keys[key];
            }
        }
        return result;
    }

    std::pair<double, double> getMousePos() {
        return {lastX, lastY};
    }

    std::pair<double, double> getMouseOffset() {
        return {xOffset, yOffset};
    }

    std::pair<double, double> getScroll() {
        return {xScroll, yScroll};
    }

    bool getIsMouseButtonDown(int key) {
        bool result = false;
        if (_isEnabled) {
            auto it = _mouseButtons.find(key);
            if (it != _mouseButtons.end()) {
                result = _mouseButtons[key];
            }
        }
        return result;
    }

    static void setUpInputs(GLFWwindow *window) {
        glfwSetKeyCallback(window, callBack);
    }

    static void setUpMouseInputs(GLFWwindow *window) {
        glfwSetCursorPosCallback(window, mouseCallBack);
    }

    static void setUpMouseButton(GLFWwindow *window) {
        glfwSetMouseButtonCallback(window, mouseButtonCallBack);
    }

    static void setUpScroll(GLFWwindow *window) {
        glfwSetScrollCallback(window, scroll_callback);
    }

private:
    static void callBack(GLFWwindow *window, int key, int scancode, int action, int mods) {
        for (auto input : _instances) {
            input->setIsKeyDown(key, action != GLFW_RELEASE);
        }
    }

    static void mouseCallBack(GLFWwindow *window, double xpos, double ypos) {
        for (auto input : _instances) {
            input->firstMouse = false;
            input->xOffset = xpos - input->lastX;
            input->yOffset = ypos - input->lastY;
            input->lastX = xpos;
            input->lastY = ypos;
        }
    }

    static void mouseButtonCallBack(GLFWwindow *window, int button, int action, int mods) {
        for (auto input : _instances) {
            input->setMouseButtonIsDown(button, action != GLFW_RELEASE);
        }
    }

    static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
        for (auto input : _instances) {
            input->xScroll = xoffset;
            input->yScroll = yoffset;
        }
    }

    void setIsKeyDown(int key, bool isDown) {
        auto it = _keys.find(key);
        if (it != _keys.end()) {
            _keys[key] = isDown;
        }
    }

    void setMouseButtonIsDown(int key, bool isDown) {
        auto it = _mouseButtons.find(key);
        if (it != _mouseButtons.end()) {
            _mouseButtons[key] = isDown;
        }
    }

    static std::vector<Input *> _instances;
    std::map<int, bool> _keys;
    std::map<int, bool> _mouseButtons;
    bool _isEnabled;

    bool firstMouse = true;
    double lastX = 0, lastY = 0;
    double xOffset, yOffset;
    double xScroll, yScroll;
};

#endif //CLOCKWORKENGINE_INPUT_H