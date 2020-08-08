//
// Created by Andrew Knee on 7/22/2020.
//

#ifndef VOXELGAME_ENTITY_H
#define VOXELGAME_ENTITY_H

#include "Defines.h"
#include <memory>

namespace ClockworkEngine {
    class Engine;

    class Entity {
    private:
        ObjectID m_id;

        std::weak_ptr<Engine> engine;
    public:
        Entity(std::shared_ptr<Engine> engine);

        Entity(ObjectID id, std::shared_ptr<Engine> engine);

        bool operator==(const Entity &rhs) const;

        bool operator!=(const Entity &rhs) const;

        Entity operator=(const Entity temp);

        Entity *operator=(Entity *temp);

        ObjectID getID();

        void setID(ObjectID ID);

        virtual ~Entity();
    };
}


#endif //VOXELGAME_ENTITY_H
