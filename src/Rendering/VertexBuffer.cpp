//
// Created by Andrew Knee on 11/30/2020.
//

#include "Rendering/VertexBuffer.h"

namespace ClockworkEngine {

    void VertexBuffer::init(unsigned int size) {
        glCreateBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
        this->size = size;
    }

    void VertexBuffer::init(glm::vec3* vertices, unsigned int size) {
        glCreateBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW);
        this->size = size;
    }

    VertexBuffer::~VertexBuffer() {
        glDeleteBuffers(1, &VBO);
    }

    void VertexBuffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
    }

    void VertexBuffer::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::updateData(glm::vec3 *vertices, unsigned int size) {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, vertices);
    }

    void VertexBuffer::updateData(glm::vec3 *vertices, unsigned int size, unsigned int offset) {
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, offset, size, vertices);
    }

    unsigned int &VertexBuffer::getSize() {
        return size;
    }

    IndexBuffer::~IndexBuffer() {
        glDeleteBuffers(1, &IBO);
    }

    void IndexBuffer::init(unsigned int size) {
        glCreateBuffers(1, &IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
        this->size = size;
    }

    void IndexBuffer::init(glm::ivec3 *indices, unsigned int size) {
        glCreateBuffers(1, &IBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_DYNAMIC_DRAW);
        this->size = size;
    }

    void IndexBuffer::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    }

    void IndexBuffer::unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void IndexBuffer::updateData(glm::ivec3 *indices, unsigned int size) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, size, indices);
    }

    void IndexBuffer::updateData(glm::ivec3 *indices, unsigned int size, unsigned int offset) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, size, indices);
    }

    unsigned int &IndexBuffer::getSize() {
        return size;
    }


}
