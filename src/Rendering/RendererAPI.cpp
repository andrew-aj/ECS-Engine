//
// Created by andre on 11/22/2020.
//

#include "Rendering/RendererAPI.h"
#include "OpenGL/OpenGLAPI.h"

namespace ClockworkEngine {

    RendererAPI * RendererAPI::createAPI(Renderer API) {
        switch (API) {
            case Renderer::None:
                Log::writeError("API of type None is currently not support.");
                return nullptr;
            case Renderer::OpenGL:
                return new OpenGLAPI();
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

    RendererAPI::Renderer RendererAPI::stringToEnum(const std::string &input) {
        if (input == "OpenGL") {
            return Renderer::OpenGL;
        } else if (input == "Vulkan") {
            return Renderer::Vulkan;
        } else if (input == "DirectX11") {
            return Renderer::DirectX11;
        } else if (input == "DirectX12") {
            return Renderer::DirectX12;
        } else {
            return Renderer::None;
        }
    }
}
