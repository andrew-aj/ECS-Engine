//
// Created by andre on 11/22/2020.
//

#ifndef CLOCKWORKENGINE_RENDERERAPI_H
#define CLOCKWORKENGINE_RENDERERAPI_H

#include <glad/glad.h>
#include <memory>
#include <vector>
#include "Main/Log.h"
#include "Main/Defines.h"

namespace ClockworkEngine {

    class RendererAPI {
    public:
        RendererAPI() = default;

        void init();

        void draw();
    private:

    };

}


#endif //CLOCKWORKENGINE_RENDERERAPI_H
