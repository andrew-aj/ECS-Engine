//
// Created by Andrew Knee on 10/17/2020.
//

#ifndef CLOCKWORKENGINE_DEFAULTCOMPONENTS_H
#define CLOCKWORKENGINE_DEFAULTCOMPONENTS_H

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/glm.hpp>

namespace ClockworkEngine {
    struct Transform {
        glm::vec3 position;
        glm::quat quatRotation;
        glm::vec3 scale;

        glm::quat degreeToQuat(glm::vec3 angle) {
            quatRotation = glm::quat(glm::radians(angle));
            return quatRotation;
        }

        static glm::quat degreeToQuat(glm::quat quatRotation, glm::vec3 angle) {
            quatRotation = glm::quat(glm::radians(angle));
            return quatRotation;
        }

        glm::quat radiansToQuat(glm::vec3 angle) {
            quatRotation = glm::quat(angle);
            return quatRotation;
        }

        static glm::quat radiansToQuat(glm::quat quatRotation, glm::vec3 angle) {
            quatRotation = glm::quat(angle);
            return quatRotation;
        }

        glm::quat axisToQuat(float rotationRads, glm::vec3 rotationAxis) {
            quatRotation = glm::angleAxis(rotationRads, rotationAxis);
            return quatRotation;
        }

        static glm::quat axisToQuat(glm::quat quatRotation, float rotationRads, glm::vec3 rotationAxis) {
            quatRotation = glm::angleAxis(rotationRads, rotationAxis);
            return quatRotation;
        }

        glm::mat4 toMat4(){
            return glm::toMat4(quatRotation);
        }

        static glm::mat4 toMat4(glm::quat quaternion){
            return glm::toMat4(quaternion);
        }

        glm::vec3 toEuler(){
            return glm::eulerAngles(quatRotation);
        }

        static glm::vec3 toEuler(glm::quat quatRotation){
            return glm::eulerAngles(quatRotation);
        }
    };
}

#endif //CLOCKWORKENGINE_DEFAULTCOMPONENTS_H
