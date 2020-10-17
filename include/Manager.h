//
// Created by Andrew Knee on 9/28/2020.
//

#ifndef CLOCKWORKENGINE_MANAGER_H
#define CLOCKWORKENGINE_MANAGER_H

#include "Defines.h"
#include "Container.h"
#include "Component.h"
#include <queue>
#include <memory>
#include <map>
#include <type_traits>
#include <assert.h>
#include <typeinfo>
#include <typeindex>
#include <any>

namespace ClockworkEngine {
    class Manager {
    public:
        Manager();

        EntityID createEntity();

        void freeEntity(EntityID entity);

        template<class T>
        std::shared_ptr<T> createComponent(EntityID entity);

        template<typename T>
        void removeComponent(EntityID entityId);

        template<typename T>
        std::shared_ptr<T> getComponent(EntityID entity);

        template<typename T>
        std::pair<std::map<EntityID, std::any>::iterator, std::map<EntityID, std::any>::iterator> getEntities();

    private:
        //Container<EntityID> entityStorage; // = Container<EntityID>();
        //Container<Container<Component>> componentStorage;
        std::queue<EntityID> freeIDs;
        std::map<std::type_index, ComponentID> componentToID;
        //std::vector<std::map<EntityID, std::shared_ptr<Component>>> componentMap;
        std::map<ComponentID, std::map<EntityID, std::any>> componentMap;

        EntityID nextID = 0;
        ComponentID nextComponentID = 0;
    };
}

#endif //CLOCKWORKENGINE_MANAGER_H
