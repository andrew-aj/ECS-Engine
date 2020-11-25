//
// Created by andre on 11/22/2020.
//

#ifndef CLOCKWORKENGINE_RENDERERAPI_H
#define CLOCKWORKENGINE_RENDERERAPI_H

#include <glad/glad.h>
#include <memory>
#include "Main/Log.h"

namespace ClockworkEngine {

    class RendererAPI {
    public:
        enum class Renderer {
            None,
            OpenGL,
            Vulkan,
            DirectX11,
            DirectX12
        };

        static Renderer stringToEnum(const std::string &input);

        virtual void init() = 0;

        static Renderer getCurrentAPI();

        static RendererAPI* createAPI(Renderer API);

    private:
        static Renderer CurrentAPI;
    };

}


#endif //CLOCKWORKENGINE_RENDERERAPI_H
