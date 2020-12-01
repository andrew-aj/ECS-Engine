//
// Created by Andrew Knee on 10/27/2020.
//
#include "Main/Camera.h"

namespace ClockworkEngine {
    Camera::Camera(Manager *manager, glm::vec3 position, glm::vec3 Up) : front(glm::vec3(0.0, 0.0, -1.0)) {
        this->manager = manager;
        entityId = manager->createEntity();
        transform = manager->createComponent<Transform>(entityId);

        transform->setPosition(position);
        transform->degreeToQuat({0.0, 0.0, -90.0});
        this->worldUp = Up;
        updateCameraVectors();
    }

    Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : front(glm::vec3(0.0f, 0.0f, -1.0f)) {
        this->manager = manager;
        entityId = manager->createEntity();
        transform = manager->createComponent<Transform>(entityId);

        transform->setPosition(glm::vec3(posX, posY, posZ));
        worldUp = glm::vec3(upX, upY, upZ);
        transform->degreeToQuat({0.0, pitch, yaw});
        updateCameraVectors();
    }

    Camera::~Camera() {
        transform.reset();
        manager->freeEntity(entityId);
        manager = nullptr;
    }

    glm::mat4 Camera::getViewMatrix() {
        auto position = transform->getPosition();
        return glm::lookAt(position, position + front, up);
    }

    std::shared_ptr<Transform> Camera::getTransform(){
        return transform;
    }


    EntityID Camera::getEntityID() {
        return entityId;
    }
}