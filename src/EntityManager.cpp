//
// Created by Andrew Knee on 7/22/2020.
//

#include "EntityManager.h"
#include "Entity.h"
#include "Engine.h"

namespace ClockworkEngine {
    EntityManager::EntityManager(std::shared_ptr<Engine> engine) {
        this->engine = engine;
        entities = Container<std::weak_ptr<Entity>>();
    }

    EntityManager::~EntityManager() {
    }

    std::shared_ptr<Entity> EntityManager::createEntity() {
        ObjectID temp = 0;
        if (!freeIDs.empty()) {
            temp = freeIDs.back();
            freeIDs.pop_back();
            auto entity = std::make_shared<Entity>(temp, engine.lock());
            entities.addItem(temp, entity);
            return entity;
        } else {
            auto entity = std::make_shared<Entity>(temp, engine.lock());
            ObjectID location = entities.addItemGetID(entity);
            entity->setID(location);
            return entity;
        }
    }

    void EntityManager::freeEntity(std::shared_ptr<Entity> entity) {
        ObjectID tempID = entity->getID();
        freeIDs.push_back(tempID);
        entity.reset();
    }
}