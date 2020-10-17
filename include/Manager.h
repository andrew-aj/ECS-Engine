//
// Created by Andrew Knee on 9/28/2020.
//

#ifndef CLOCKWORKENGINE_MANAGER_H
#define CLOCKWORKENGINE_MANAGER_H

#include "Defines.h"
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
        Manager() {
            componentToID = std::map<std::type_index, ComponentID>();
            freeIDs = std::queue<EntityID>();
            componentMap = std::map<ComponentID, std::map<EntityID, std::any>>();
        }

        EntityID createEntity() {
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

        void freeEntity(EntityID entity) {
            for(auto a : componentMap){
                auto it = a.second.find(entity);
                if(it != a.second.end()){
                    it->second.reset();
                    a.second.erase(entity);
                }
            }
            freeIDs.push(entity);
        }

        template<typename T>
        std::weak_ptr<T> createComponent(EntityID entity){
            assert(std::is_aggregate_v<T>);
            auto it = componentToID.find(typeid(T));
            if(it == componentToID.end()){
                componentToID[typeid(T)] = nextComponentID++;
            }
            std::shared_ptr<T> createdPtr = std::make_shared<T>();
            componentMap[componentToID[typeid(T)]][entity] = createdPtr;
            return createdPtr;
        }

        template <typename T>
        void removeComponent(EntityID entityId) {
            componentMap[componentToID[typeid(T)]][entityId].reset();
            componentMap[componentToID[typeid(T)]].erase(entityId);
        }

        template<typename T>
        std::shared_ptr<T> getComponent(EntityID entity) {
            return componentMap[componentToID[typeid(T)]][entity];
        }

        template<typename T>
        std::pair<std::map<EntityID, std::any>::iterator, std::map<EntityID, std::any>::iterator> getEntities() {
            return {componentMap[componentToID[typeid(T)]].begin(), componentMap[componentToID[typeid(T)]].end()};
        }

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
