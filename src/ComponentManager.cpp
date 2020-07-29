//
// Created by Andrew Knee on 7/22/2020.
//

#include "ComponentManager.h"

namespace ClockworkEngine {

    ComponentManager::ComponentManager(Engine &engine) {
        this->engine = &engine;
    }

    ComponentManager::~ComponentManager() {
        engine = nullptr;
    }

}