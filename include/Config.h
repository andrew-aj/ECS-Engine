//
// Created by Andrew Knee on 10/28/2020.
//

#ifndef CLOCKWORKENGINE_CONFIG_H
#define CLOCKWORKENGINE_CONFIG_H

#include "Defines.h"
#include <unordered_map>
#include <vector>
#include <fstream>
#include <iostream>
#include <mutex>
#include <algorithm>
#include <sstream>

namespace ClockworkEngine {
    class Config {
    public:
        Config(std::vector<std::string> valuesForConfig);

        Config(std::vector<std::string> valuesForConfig, const std::string &filePath);

        ~Config();

        bool loadConfig(const std::string &filePath);

        bool writeConfig(const std::string &filePath);

        bool loadConfig();

        bool writeConfig();
    private:
        std::unordered_map<std::string, std::string> configValues;
        static std::vector<std::string> configFiles;
        const std::string &FilePath;
        std::mutex m;
    };
}


#endif //CLOCKWORKENGINE_CONFIG_H
