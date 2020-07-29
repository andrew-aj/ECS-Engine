//
// Created by Andrew Knee on 7/22/2020.
//

#ifndef VOXELGAME_ENTITY_H
#define VOXELGAME_ENTITY_H

#include "Defines.h"

namespace ClockworkEngine {
    class Engine;

    class Entity {
    private:
        ObjectID m_id;

        Engine *engine;
    public:
        Entity(Engine *engine);

        Entity(ObjectID id, Engine *engine);

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
