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
        const ObjectID m_id;
        static inline ObjectID m_nextID = 0;

        Engine *engine;
    public:
        Entity(Engine *engine);

        Entity(ObjectID id, Engine *engine);

        bool operator==(const Entity &rhs) const;

        bool operator!=(const Entity &rhs) const;

        Entity operator=(const Entity temp);

        Entity *operator=(const Entity *temp);

        ObjectID getID() const;

        virtual ~Entity();
    };
}


#endif //VOXELGAME_ENTITY_H
