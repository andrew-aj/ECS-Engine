//
// Created by Andrew Knee on 7/24/2020.
//

#include "Manager.h"
#include "Defines.h"

struct temp{};

int main(){
    ClockworkEngine::Manager manager;
    ClockworkEngine::EntityID ent = manager.createEntity();
    auto comp = manager.createComponent<temp>(ent);
    //auto val = manager.getEntities<temp>();

    return 0;
}