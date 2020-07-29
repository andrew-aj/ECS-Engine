//
// Created by Andrew Knee on 7/22/2020.
//

#include "Engine.h"

namespace ClockworkEngine {
    Engine::Engine() : m_entityManager(new EntityManager(*this)), m_componentManager(new ComponentManager(*this)),
                       m_systemManager(new SystemManager(*this)) {

    }

    Engine::~Engine() {
        delete m_entityManager;
        delete m_componentManager;
        delete m_systemManager;
    }
}
