//
// Created by Andrew Knee on 9/28/2020.
//

#ifndef CLOCKWORKENGINE_MANAGER_H
#define CLOCKWORKENGINE_MANAGER_H

#include "Main/Defines.h"
#include <queue>
#include <memory>
#include <map>
#include <type_traits>
#include <typeinfo>
#include <typeindex>
#include <any>
#include <utility>
#include <algorithm>

namespace ClockworkEngine {

    /**
     * Manager class that stores and keeps track of the entities and components.
     */
    class Manager {
    public:
        /**
         * Creates the containers.
         */
        Manager() {
            componentToID = std::map<std::type_index, ComponentID>();
            freeIDs = std::queue<EntityID>();
            componentMap = std::map<ComponentID, std::map<EntityID, std::any>>();
        }

        ~Manager(){
            componentToID.clear();
            componentMap.clear();
            freeIDs = {};
        }

        /**
         * Creates and entity and increments the next available ID.
         * If there is a free ID then it takes that to conserve memory and reduce the max ID value used.
         * @return EntityID that stores the integer ID value for the entity created.
         */
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

        /**
         * Frees and entity and removes all of its components. Adds it to the list of
         * free entity IDs.
         * @param entity EntityID to use.
         */
        void freeEntity(EntityID entity) {
            for (auto a : componentMap) {
                auto it = a.second.find(entity);
                if (it != a.second.end()) {
                    it->second.reset();
                    a.second.erase(entity);
                }
            }
            freeIDs.push(entity);
        }

        /**
         * Creates a component and adds it to the entity ID.
         * @tparam T Component type.
         * @param entity EntityID to assign component to.
         * @return Weak_ptr of type T to eliminate conflicting ptr problems.
         */
        template<typename T, typename... Args>
        std::shared_ptr<T> createComponent(EntityID entity, Args &&... args) {
            auto it = componentToID.find(typeid(T));
            if (it == componentToID.end()) {
                componentToID[typeid(T)] = nextComponentID++;
            }
            std::shared_ptr<T> createdPtr = std::make_shared<T>(std::forward<Args>(args)...);
            componentMap[componentToID[typeid(T)]][entity] = createdPtr;
            return createdPtr;
        }

        /**
         * Removes the component from the associated entity.
         * @tparam T Component type.
         * @param entityId EntityID to assign component to.
         */
        template<typename T>
        void removeComponent(EntityID entityId) {
            componentMap[componentToID[typeid(T)]][entityId].reset();
            componentMap[componentToID[typeid(T)]].erase(entityId);
        }

        /**
         * Gets the component of type T for the entity.
         * @tparam T Component type.
         * @param entity EntityID to assign component to.
         * @return Weak_ptr of type T containing the component data.
         */
        template<typename T>
        std::shared_ptr<T> getComponent(EntityID entity) {
            if (componentMap[componentToID[typeid(T)]].find(entity) != componentMap[componentToID[typeid(T)]].end()) {
                return std::any_cast<std::shared_ptr<T>>(componentMap[componentToID[typeid(T)]][entity]);
            }else{
                return nullptr;
            }
        }

        /**
         * Gets the entities with a component of type T.
         * @tparam T Component type.
         * @return std::pair of index 0 equal to iterator.begin() and index 1 equal to iterator.end().
         */
        template<typename T>
        std::pair<typename std::map<EntityID, T>::iterator, typename std::map<EntityID, T>::iterator> getEntities() {
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
