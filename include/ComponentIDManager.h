//
// Created by Andrew Knee on 7/25/2020.
//

#ifndef CLOCKWORKENGINE_COMPONENTIDMANAGER_H
#define CLOCKWORKENGINE_COMPONENTIDMANAGER_H

#include <unordered_map>
#include <vector>
#include "Defines.h"

namespace ClockworkEngine {
    class Component;

    class ComponentIDManager {
    private:
        std::unordered_map<size_t, ComponentID> componentMap;

        std::vector<ComponentID> recycledIDs();

        static inline i64 ID = 1;
    public:
        ComponentIDManager();

        i64 getID(const std::type_info& info);
    };
}

#endif //CLOCKWORKENGINE_COMPONENTIDMANAGER_H
