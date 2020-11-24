//
// Created by Andrew Knee on 10/29/2020.
//

#ifndef CLOCKWORKENGINE_MESHRENDERER_H
#define CLOCKWORKENGINE_MESHRENDERER_H

#include "Manager.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace ClockworkEngine {
    class MeshRenderer {
    public:
        MeshRenderer(Manager *manager);

        ~MeshRenderer();

    private:
        Manager *manager;

        void initialize();
    };
}

#endif //CLOCKWORKENGINE_MESHRENDERER_H
