//
// Created by Andrew Knee on 10/28/2020.
//

#include "Config.h"

namespace ClockworkEngine{
    Config::Config(std::vector<std::string> valuesForConfig) {
        for(auto& i : valuesForConfig){
            configValues.insert({i, nullptr});
        }
    }

    Config::~Config() {
        configValues.erase(configValues.begin(), configValues.end());
    }
}
