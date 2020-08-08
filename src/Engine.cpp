//
// Created by Andrew Knee on 7/22/2020.
//

#include "Engine.h"

namespace ClockworkEngine {
    Engine::Engine() : m_entityManager(new EntityManager(shared_from_this())), m_componentManager(std::make_shared<ComponentManager>(shared_from_this())),
                       m_systemManager(new SystemManager(shared_from_this())) {

    }

    Engine::~Engine() {
    }
}
