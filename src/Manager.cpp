//
// Created by Andrew Knee on 9/28/2020.
//

#include "Manager.h"

namespace ClockworkEngine {
    Manager::Manager() {
        componentToID = std::map<std::type_index, ComponentID>();
        freeIDs = std::queue<EntityID>();
        componentMap = std::map<ComponentID, std::map<EntityID, std::any>>();
    }

    EntityID Manager::createEntity() {
        EntityID temp;
        if (!freeIDs.empty()) {
            temp = freeIDs.front();
            freeIDs.pop();
            //entityStorage.addItem(temp);
            return temp;
        } else {
            temp = nextID++;
            //entityStorage.addItem(temp);
            return temp;
        }

    }

    void Manager::freeEntity(EntityID entity) {
        for(auto a : componentMap){
            auto it = a.second.find(entity);
            if(it != a.second.end()){
                it->second.reset();
                a.second.erase(entity);
            }
        }
        freeIDs.push(entity);
    }

    template <class T>
    std::shared_ptr<T> Manager::createComponent(EntityID entity){
        assert(std::is_aggregate_v<T>);
        auto it = componentToID.find(typeid(T));
        if(it == componentToID.end()){
            componentToID[typeid(T)] = nextComponentID++;
        }
        std::shared_ptr<T> createdPtr;
        componentMap[componentToID[typeid(T)]][entity] = createdPtr;
        return createdPtr;
    }

    template <typename T>
    void Manager::removeComponent(EntityID entityId) {
        componentMap[componentToID[typeid(T)]].erase(entityId);
    }

    template<typename T>
    std::shared_ptr<T> Manager::getComponent(EntityID entity) {
        return componentMap[componentToID[typeid(T)]][entity];
    }

    template<typename T>
    std::pair<std::map<EntityID, std::any>::iterator, std::map<EntityID, std::any>::iterator> Manager::getEntities() {
        return {componentMap[componentToID[typeid(T)]].begin(), componentMap[componentToID[typeid(T)]].end()};
    }


}