//
// Created by Andrew Knee on 7/22/2020.
//

#ifndef VOXELGAME_ENTITYMANAGER_H
#define VOXELGAME_ENTITYMANAGER_H

#include "Defines.h"
#include "Container.h"
#include <vector>
#include <memory>

namespace ClockworkEngine {

    class Entity;

    class Engine;

    class EntityManager {

    private:
        std::weak_ptr<Engine> engine;

        Container<std::weak_ptr<Entity>> entities;
        std::vector<ObjectID> freeIDs;
    public:
        explicit EntityManager(std::shared_ptr<Engine> engine);

        std::shared_ptr<Entity> createEntity();

        void freeEntity(std::shared_ptr<Entity> entity);

        virtual ~EntityManager();
    };
}


#endif //VOXELGAME_ENTITYMANAGER_H
