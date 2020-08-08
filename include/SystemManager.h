//
// Created by Andrew Knee on 7/22/2020.
//

#ifndef VOXELGAME_SYSTEMMANAGER_H
#define VOXELGAME_SYSTEMMANAGER_H

#include <Defines.h>
#include <memory>

namespace ClockworkEngine {

    class Engine;
    class System;

    class SystemManager {
    private:
        std::weak_ptr<Engine> engine;
    public:
        SystemManager(std::shared_ptr<Engine> engine);

        virtual ~SystemManager();
    };
}

#endif //VOXELGAME_SYSTEMMANAGER_H
