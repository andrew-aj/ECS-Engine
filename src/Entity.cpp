//
// Created by Andrew Knee on 7/22/2020.
//

#include "Entity.h"

namespace ClockworkEngine {
    Entity::Entity(Engine *engine) {
        this->engine = engine;
    }

    Entity::Entity(ObjectID id, Engine *engine) : m_id(id) {
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
        return Entity(temp.getID(), this->engine);
    }

    Entity *Entity::operator=(Entity *temp) {
        return new Entity(temp->getID(), this->engine);
    }

    Entity::~Entity() {
        engine = nullptr;
    }

    void Entity::setID(ObjectID ID) {
        m_id = ID;
    }
}