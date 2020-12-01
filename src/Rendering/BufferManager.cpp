//
// Created by Andrew Knee on 11/30/2020.
//

#include "Rendering/BufferManager.h"

#include <utility>

namespace ClockworkEngine{

    BufferManager::BufferManager(std::shared_ptr<VertexBuffer> vertexBuffer, std::shared_ptr<IndexBuffer> indexBuffer) {
        this->vertexBuffer = vertexBuffer;
        this->indexBuffer = indexBuffer;
        glGenVertexArrays(1, &VAO);
    }

    void BufferManager::init() {
        indexBuffer->bind();
        vertexBuffer->bind();
        glBindVertexArray(VAO);
        for(int i = 0; i < textures.size(); i++){
            textures[i].bindTexture(i);
        }
    }

    void BufferManager::setAttributes() {
        for(auto a : attribs){
            glVertexAttribPointer(a.index, a.size, a.type, a.normalized, a.stride, reinterpret_cast<void*>(a.offset));
            glEnableVertexAttribArray(a.index);
        }
    }

    void BufferManager::unbind() {
        indexBuffer->unbind();
        vertexBuffer->unbind();
        glBindVertexArray(0);
    }

    void BufferManager::addTexture(Texture& texture) {
        textures.push_back(texture);
    }

    unsigned int &BufferManager::getVertices() {
        return indexBuffer->getSize();
    }

    void BufferManager::addAttribs(attribManager manager) {
        attribs.push_back(manager);
    }

}