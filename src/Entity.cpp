//
// Created by Andrew Knee on 7/22/2020.
//

#include "Entity.h"

namespace ClockworkEngine {
    Entity::Entity(std::shared_ptr<Engine> engine) {
        this->engine = engine;
    }

    Entity::Entity(ObjectID id, std::shared_ptr<Engine> engine) : m_id(id) {
        this->engine = engine;
    }

    ObjectID Entity::getID() {
        return m_id;
    }

    bool Entity::operator==(const Entity &rhs) const {
        return m_id == rhs.m_id;
    }

    bool Entity::operator!=(const Entity &rhs) const {
        return !(rhs == *this);
    }

    Entity Entity::operator=(Entity temp) {
        return Entity(temp.getID(), this->engine.lock());
    }

    Entity *Entity::operator=(Entity *temp) {
        return new Entity(temp->getID(), this->engine.lock());
    }

    Entity::~Entity() {
    }

    void Entity::setID(ObjectID ID) {
        m_id = ID;
    }
}