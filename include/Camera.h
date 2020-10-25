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
        Camera(Manager *manager) {
            this->manager = manager;
            entityId = manager->createEntity();
            transform = manager->createComponent<Transform>(entityId);
        }

    private:
        Manager *manager;
        EntityID entityId;
        std::weak_ptr<Transform> transform;
    };
}
#endif //CLOCKWORKENGINE_CAMERA_H
