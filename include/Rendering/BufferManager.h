//
// Created by Andrew Knee on 11/30/2020.
//

#ifndef CLOCKWORKENGINE_BUFFERMANAGER_H
#define CLOCKWORKENGINE_BUFFERMANAGER_H

#include "VertexBuffer.h"
#include "Main/DefaultComponents.h"
#include <memory>
#include <iostream>

namespace ClockworkEngine {

    struct attribManager{
        int index;
        int size;
        GLenum type;
        GLboolean normalized;
        int stride;
        int offset;

        attribManager(int index, int size, GLenum type, GLboolean normalized, int stride, int offset){
            this->index = index;
            this->size = size;
            this->type = type;
            this->normalized = normalized;
            switch (type) {
                case GL_BYTE:
                    this->stride = stride;
                    this->offset = offset;
                    break;
                case GL_UNSIGNED_BYTE:
                    this->stride = stride;
                    this->offset = offset;
                    break;
                case GL_SHORT:
                    this->stride = stride * (int)sizeof(short);
                    this->offset = offset * (int)sizeof(short);
                    break;
                case GL_UNSIGNED_SHORT:
                    this->stride = stride * (int)sizeof(short);
                    this->offset = offset * (int)sizeof(short);
                    break;
                case GL_INT:
                    this->stride = stride * (int)sizeof(int);
                    this->offset = offset * (int)sizeof(int);
                    break;
                case GL_UNSIGNED_INT:
                    this->stride = stride * (int)sizeof(int);
                    this->offset = offset * (int)sizeof(int);
                    break;
                case GL_FIXED:
                    this->stride = stride * (int)sizeof(int);
                    this->offset = offset * (int)sizeof(int);
                    break;
                case GL_HALF_FLOAT:
                    this->stride = stride * 2;
                    this->offset = offset * 2;
                    break;
                case GL_FLOAT:
                    this->stride = stride * (int)sizeof(float);
                    this->offset = offset * (int)sizeof(float);
                    break;
                case GL_DOUBLE:
                    this->stride = stride * (int)sizeof(double);
                    this->offset = offset * (int)sizeof(double);
                    break;
                default:
                    Log::writeError(&"Bad GLenum type of " [ type]);
                    throw "Bad GLenum type";
            }
        }

    };

    class BufferManager {
    public:
        BufferManager(std::shared_ptr<VertexBuffer> vertexBuffer, std::shared_ptr<IndexBuffer> indexBuffer);

        void init();

        void setAttributes(attribManager manager);

        void unbind();

        void addTexture(Texture& texture);
    private:
        std::shared_ptr<VertexBuffer> vertexBuffer;
        std::shared_ptr<IndexBuffer> indexBuffer;
        std::vector<Texture> textures;
        unsigned int VAO;
    };

}


#endif //CLOCKWORKENGINE_BUFFERMANAGER_H
