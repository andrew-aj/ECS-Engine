//
// Created by andre on 11/22/2020.
//

#include "Rendering/RendererAPI.h"
#include <cstring>

namespace ClockworkEngine {

    void OpenGLCallback(unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length,
                        const char *message, const void *userParam) {
        switch (severity) {
            case GL_DEBUG_SEVERITY_LOW: {
                char *finalMessage = new char[strlen("GL_SEVERITY_LOW:") + length];
                strcat(finalMessage, "GL_SEVERITY_LOW:");
                strcat(finalMessage, message);
                Log::writeError(finalMessage);
                delete[] finalMessage;
                break;
            }
            case GL_DEBUG_SEVERITY_MEDIUM: {
                char *finalMessage = new char[strlen("GL_SEVERITY_MEDIUM:") + length];
                strcat(finalMessage, "GL_SEVERITY_MEDIUM:");
                strcat(finalMessage, message);
                Log::writeError(finalMessage);
                delete[] finalMessage;
                break;
            }
            case GL_DEBUG_SEVERITY_HIGH: {
                char *finalMessage = new char[strlen("GL_SEVERITY_HIGH:") + length];
                strcat(finalMessage, "GL_SEVERITY_HIGH:");
                strcat(finalMessage, message);
                Log::writeError(finalMessage);
                delete[] finalMessage;
                break;
            }
            case GL_DEBUG_SEVERITY_NOTIFICATION: {
                char *finalMessage = new char[strlen("GL_SEVERITY_NOTIFICATION:") + length];
                strcat(finalMessage, "GL_SEVERITY_NOTIFICATION:");
                strcat(finalMessage, message);
                Log::writeError(finalMessage);
                delete[] finalMessage;
                break;
            }
            default: {
                char *finalMessage = new char[strlen("UNKNOWN_SEVERITY:") + length];
                strcat(finalMessage, "UNKNOWN_SEVERITY:");
                strcat(finalMessage, message);
                Log::writeError(finalMessage);
                delete[] finalMessage;
                break;
            }
        }
    }

    void RendererAPI::init() {
#ifndef DEBUG
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(OpenGLCallback, nullptr);

        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif
        glEnable(GL_DEPTH_TEST);
    }
}
