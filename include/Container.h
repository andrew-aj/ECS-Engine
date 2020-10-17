//
// Created by Andrew Knee on 7/24/2020.
//

#ifndef VOXELGAME_CONTAINER_H
#define VOXELGAME_CONTAINER_H

#include "Defines.h"
#include <vector>

namespace ClockworkEngine {

    template<typename T>
    class Container {
    private:
        i64 m_size;
        i64 highestValue = 0;
        std::vector<T> contents;
    public:
        Container() {
            allocate(5);
        }

        Container(i64 size) {
            allocate(size);
        }

        T getItem(i64 index) {
            return contents[index];
        }

        void addItem(T item) {
            if (highestValue == m_size) {
                allocate((m_size * 2) + 1);
            }
            contents[highestValue++] = item;
        }

        i64 addItemGetID(T item) {
            if (highestValue == m_size) {
                allocate((m_size * 2) + 1);
            }
            i64 tempLocation = highestValue++;
            contents[tempLocation] = item;
            return tempLocation;
        }

        void addItem(i64 index, T item) {
            if (index >= m_size) {
                allocate((index * 2) + 1);
            }
            contents[index] = item;
            highestValue = index;
        }

        void allocate(i64 size) {
            contents.reserve(size);
            m_size = size;
        }

        i64 getMSize() const {
            return m_size;
        }

        bool empty(){
            if(m_size > 0){
                return false;
            }else {
                return true;
            }
        }

        i64 getHighestValue() const {
            return highestValue;
        }

        virtual ~Container() {
        }
    };
}

#endif //VOXELGAME_CONTAINER_H
