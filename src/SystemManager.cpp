//
// Created by Andrew Knee on 7/22/2020.
//

#include "SystemManager.h"

namespace ClockworkEngine {
    SystemManager::SystemManager(std::shared_ptr<Engine> engine) {
        this->engine = engine;
    }

    SystemManager::~SystemManager() {
    }
}
