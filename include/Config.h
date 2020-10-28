//
// Created by Andrew Knee on 10/28/2020.
//

#ifndef CLOCKWORKENGINE_CONFIG_H
#define CLOCKWORKENGINE_CONFIG_H

#include "Defines.h"
#include <unordered_map>
#include <vector>

namespace ClockworkEngine {
    class Config {
    public:
        Config(std::vector<std::string> valuesForConfig);
        ~Config();
    private:
        std::unordered_map<std::string, std::string> configValues;
    };
}


#endif //CLOCKWORKENGINE_CONFIG_H
