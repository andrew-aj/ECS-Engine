//
// Created by Andrew Knee on 7/22/2020.
//

#ifndef VOXELGAME_SYSTEMMANAGER_H
#define VOXELGAME_SYSTEMMANAGER_H

#include <Defines.h>

namespace ClockworkEngine {

    class Engine;
    class System;

    class SystemManager {
    private:
        Engine *engine;
    public:
        SystemManager(Engine &engine);

        virtual ~SystemManager();
    };
}

#endif //VOXELGAME_SYSTEMMANAGER_H
