//
// Created by andre on 11/22/2020.
//

#ifndef CLOCKWORKENGINE_OPENGLAPI_H
#define CLOCKWORKENGINE_OPENGLAPI_H

#include <Rendering/RendererAPI.h>

namespace ClockworkEngine {

    class OpenGLAPI : public RendererAPI {
    public:
        void init() override;
    };

}


#endif //CLOCKWORKENGINE_OPENGLAPI_H
