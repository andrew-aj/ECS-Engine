//
// Created by andre on 11/22/2020.
//

#include "RendererAPI.h"
#include "OpenGLAPI.h"

namespace ClockworkEngine {

    std::shared_ptr<RendererAPI> RendererAPI::createAPI(Renderer API) {
        switch (API) {
            case Renderer::None:
                Log::writeError("API of type None is currently not support.");
                return nullptr;
            case Renderer::OpenGL:
                return std::make_shared<OpenGLAPI>();
            case Renderer::DirectX11:
                Log::writeError("API of type DirectX11 is currently not support.");
                return nullptr;
            case Renderer::DirectX12:
                Log::writeError("API of type DirectX12 is currently not support.");
                return nullptr;
            case Renderer::Vulkan:
                Log::writeError("API of type Vulkan is currently not support.");
                return nullptr;
        }
    }

    RendererAPI::Renderer RendererAPI::getCurrentAPI() {
        return RendererAPI::CurrentAPI;
    }
}
