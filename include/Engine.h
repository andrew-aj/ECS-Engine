//
// Created by Andrew Knee on 7/22/2020.
//

#ifndef VOXELGAME_ENGINE_H
#define VOXELGAME_ENGINE_H

#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"
#include "Defines.h"

namespace ClockworkEngine {
    class Engine {
    private:
        EntityManager *m_entityManager;
        ComponentManager *m_componentManager;
        SystemManager *m_systemManager;

        Timestep timestep;
    public:
        Engine();
        virtual ~Engine();
    };
}


#endif //VOXELGAME_ENGINE_H
