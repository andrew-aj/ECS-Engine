//
// Created by Andrew Knee on 7/24/2020.
//

#include "Main/Manager.h"
#include "Main/Defines.h"
#include <iostream>

struct temp {
    int x, y;
};

int main() {
    ClockworkEngine::Manager manager;
    ClockworkEngine::EntityID ent = manager.createEntity();


    return 0;
}