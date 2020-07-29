//
// Created by Andrew Knee on 7/22/2020.
//

#include "EntityManager.h"
#include "Entity.h"
#include "Engine.h"

namespace ClockworkEngine {
    EntityManager::EntityManager(Engine &engine) {
        this->engine = &engine;
        entities = new Container<Entity *>();
    }

    EntityManager::~EntityManager() {
        engine = nullptr;
    }

    Entity *EntityManager::createEntity() {
        Entity *temp = new Entity(engine);
        entities->addItem(temp->getID(), temp);
        return temp;
    }
}