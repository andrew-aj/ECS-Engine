//
// Created by Andrew Knee on 10/24/2020.
//

#ifndef CLOCKWORKENGINE_CAMERA_H
#define CLOCKWORKENGINE_CAMERA_H

#include "Defines.h"
#include "DefaultComponents.h"
#include "Manager.h"
#include <memory>

namespace ClockworkEngine {

    enum CameraMovement {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
    };

    class Camera {
    public:
        Camera(Manager *manager, glm::vec3 position, glm::vec3 Up = glm::vec3(0.0, 1.0, 0.0));

        Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

        ~Camera();

        glm::mat4 getViewMatrix();

        std::shared_ptr<Transform> getTransform();

        EntityID getEntityID();

    private:
        Manager *manager;
        EntityID entityId;
        //For euler angles x is roll, y is pitch, z is yaw
        std::shared_ptr<Transform> transform;

        glm::vec3 front;
        glm::vec3 up;
        glm::vec3 worldUp;
        glm::vec3 right;

        void updateCameraVectors()
        {
            glm::vec3 euler = transform->toEuler();
            glm::vec3 front2;
            front2.x = cos(glm::radians(euler.z)) * cos(glm::radians(euler.y));
            front2.y = sin(glm::radians(euler.y));
            front2.z = sin(glm::radians(euler.z)) * cos(glm::radians(euler.y));
            front = glm::normalize(front2);
            right = glm::normalize(glm::cross(front, worldUp));
            up = glm::normalize(glm::cross(right, front));
        }
    };
}
#endif //CLOCKWORKENGINE_CAMERA_H
