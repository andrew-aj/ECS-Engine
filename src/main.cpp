//
// Created by Andrew Knee on 7/24/2020.
//

#include "Manager.h"
#include "Defines.h"
#include <iostream>

struct temp {
    int x, y;
};

int main() {
    ClockworkEngine::Manager manager;
    ClockworkEngine::EntityID ent = manager.createEntity();
    auto comp = manager.createComponent<temp>(ent);
    comp.lock()->x = 2;
    comp.lock()->y = 1;
    manager.removeComponent<temp>(ent);
    if (!comp.expired()) {
        //std::cout << comp.lock()->y << std::endl;
    }
    manager.freeEntity(ent);

    return 0;
}