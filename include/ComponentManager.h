//
// Created by Andrew Knee on 7/22/2020.
//

#ifndef VOXELGAME_COMPONENTMANAGER_H
#define VOXELGAME_COMPONENTMANAGER_H

#include <Defines.h>

namespace ClockworkEngine {

    class Engine;
    class Component;

    class ComponentManager {
    private:
        Engine *engine;
    public:
        ComponentManager(Engine &engine);
        virtual ~ComponentManager();
    };
}


#endif //VOXELGAME_COMPONENTMANAGER_H
