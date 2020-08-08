//
// Created by Andrew Knee on 7/22/2020.
//

#ifndef VOXELGAME_ENGINE_H
#define VOXELGAME_ENGINE_H

#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"
#include "Defines.h"
#include <memory>

namespace ClockworkEngine {
class Engine : public std::enable_shared_from_this<Engine>{
    private:
        std::shared_ptr<EntityManager> m_entityManager;
        std::shared_ptr<ComponentManager> m_componentManager;
        std::shared_ptr<SystemManager> m_systemManager;

        Timestep timestep;
    public:
        Engine();
        virtual ~Engine();
    };
}


#endif //VOXELGAME_ENGINE_H
