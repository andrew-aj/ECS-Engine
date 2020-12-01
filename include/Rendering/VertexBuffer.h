//
// Created by Andrew Knee on 11/30/2020.
//

#ifndef CLOCKWORKENGINE_VERTEXBUFFER_H
#define CLOCKWORKENGINE_VERTEXBUFFER_H

#include "Main/Defines.h"
#include "Main/Log.h"
#include "glad/glad.h"
#include <iostream>
#include <memory>
#include <glm/glm.hpp>

namespace ClockworkEngine {

    class VertexBuffer {
    public:
        VertexBuffer() = default;
        ~VertexBuffer();

        void init(unsigned int size);
        void init(glm::vec3* vertices, unsigned int size);

        void bind() const;

        void unbind() const;

        void updateData(glm::vec3* vertices, unsigned int size);
        void updateData(glm::vec3* vertices, unsigned int size, unsigned int offset);

    private:
        unsigned int VBO;
    };

    class IndexBuffer{
    public:
        IndexBuffer() = default;
        ~IndexBuffer();

        void init(unsigned int size);
        void init(glm::ivec3* indices, unsigned int size);

        void bind() const;

        void unbind() const;

        void updateData(glm::ivec3* indices, unsigned int size);
        void updateData(glm::ivec3* indices, unsigned int size, unsigned int offset);

    private:
        unsigned int IBO;
    };

}


#endif //CLOCKWORKENGINE_VERTEXBUFFER_H
