//
// Created by Andrew Knee on 7/24/2020.
//
#include "Engine.h"
#include "Container.h"
#include <iostream>
#include "ComponentIDManager.h"
#include "Component.h"
#include "Defines.h"

class tempcomp : public ClockworkEngine::Component{

};

class tempcomp2 : public ClockworkEngine::Component{

};

int main(){
    //ClockworkEngine::Engine engine;
    int updatesPerSecond = 60;
    ClockworkEngine::ComponentIDManager manager;
    std::cout << manager.getID(typeid(tempcomp)) << std::endl;
    std::cout << manager.getID(typeid(tempcomp2)) << std::endl;

    return 0;
}