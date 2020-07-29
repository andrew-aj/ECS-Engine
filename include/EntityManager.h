//
// Created by Andrew Knee on 7/22/2020.
//

#ifndef VOXELGAME_ENTITYMANAGER_H
#define VOXELGAME_ENTITYMANAGER_H

#include "Defines.h"
#include "Container.h"

namespace ClockworkEngine {

    class Entity;

    class Engine;

    class EntityManager {

    private:
        Engine *engine;

        Container<Entity *> *entities;
    public:
        EntityManager(Engine &engine);

        Entity *createEntity();

        virtual ~EntityManager();
    };
}


#endif //VOXELGAME_ENTITYMANAGER_H
