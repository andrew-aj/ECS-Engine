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
        ObjectID temp = 0;
        if (freeIDs.size() > 0){
            temp = freeIDs.back();
            freeIDs.pop_back();
            Entity *entity = new Entity(temp, engine);
            entities->addItem(temp, entity);
            return entity;
        }else{
            Entity *entity = new Entity(engine);
            ObjectID location = entities->addItemGetID(entity);
            entity->setID(location);
            return entity;
        }
        /*Entity *temp = new Entity(engine);
        entities->addItem(temp->getID(), temp);
        return temp;*/
    }
}