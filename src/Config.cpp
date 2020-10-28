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

    //config stored as config_string=data
    void Config::loadConfig(const std::string &filePath){
        std::string vertexCode;
        std::ifstream configFile;

        //ensure ifstream objects can throw exceptions:
        configFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try{
            if(configFile.is_open()){
                std::string line;
                while(std::getline(configFile, line)){
                    int location = line.find('=');
                    configValues[line.substr(0, location)] = line.substr(location+1);
                }
            }
        }
        catch(std::ifstream::failure& e){
            std::cout << "ERROR::CONFIG::" << filePath << "::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
        }
    }
}
