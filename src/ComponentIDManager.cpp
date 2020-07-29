//
// Created by Andrew Knee on 7/25/2020.
//

#include "ComponentIDManager.h"
#include <iostream>


namespace ClockworkEngine {

    ComponentIDManager::ComponentIDManager() {

    }

    i64 ComponentIDManager::getID(const std::type_info& info) {
        size_t hash = info.hash_code();
        if(componentMap[hash] == 0){
            i64 temp = ID++;
            componentMap[info.hash_code()] = temp;
            return temp;
        }
        return componentMap[hash];
    }

}