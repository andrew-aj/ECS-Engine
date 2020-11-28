//
// Created by Andrew Knee on 10/28/2020.
//

#include "Main/Config.h"

namespace ClockworkEngine {
    std::vector<std::string> Config::configFiles;

    Config::Config(std::vector<std::string> valuesForConfig) : FilePath(nullptr) {
        for (auto &i : valuesForConfig) {
            configValues.insert({i, nullptr});
        }
    }

    Config::Config(std::vector<std::string> valuesForConfig, const std::string &filePath) : FilePath(filePath) {
        for (auto &i : valuesForConfig) {
            configValues.insert({i, nullptr});
        }
        loadConfig(filePath);
    }

    Config::~Config() {
        configValues.erase(configValues.begin(), configValues.end());
    }

    //config stored as config_string=data
    bool Config::loadConfig(const std::string &filePath) {
        bool found = false;
        if (std::find(configFiles.begin(), configFiles.end(), filePath) == configFiles.end()) {
            configFiles.push_back(filePath);
        } else {
            found = true;
            m.lock();
        }
        std::ifstream configFile;

        //ensure ifstream objects can throw exceptions:
        configFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            if (configFile.is_open()) {
                std::string line;
                while (std::getline(configFile, line)) {
                    int location = line.find('=');
                    configValues[line.substr(0, location)] = line.substr(location + 1);
                }
                if (found) {
                    m.unlock();
                }
                return true;
            }
            if (found) {
                m.unlock();
            }
            return false;
        }
        catch (std::ifstream::failure &e) {
            std::cout << "ERROR::CONFIG::" << filePath << "::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
            if (found) {
                m.unlock();
            }
            return false;
        }
    }

    bool Config::writeConfig(const std::string &filePath) {
        bool found = false;
        if (std::find(configFiles.begin(), configFiles.end(), filePath) == configFiles.end()) {
            configFiles.push_back(filePath);
        } else {
            found = true;
            m.lock();
        }
        std::ofstream configFile;
        std::stringstream ss;

        configFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            if (configFile.is_open()) {
                for (auto &a : configValues) {
                    ss << a.first << "=" << a.second << std::endl;
                }
                configFile << ss.str();
                if (found) {
                    m.unlock();
                }
                return true;
            }
            if (found) {
                m.unlock();
            }
            return false;
        }
        catch (std::ifstream::failure &e) {
            std::cout << "ERROR::CONFIG::" << filePath << "::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
            if (found) {
                m.unlock();
            }
            return false;
        }
    }

    bool Config::loadConfig() {
        bool found = false;
        if (std::find(configFiles.begin(), configFiles.end(), FilePath) == configFiles.end()) {
            configFiles.push_back(FilePath);
        } else {
            found = true;
            m.lock();
        }
        std::ifstream configFile;

        //ensure ifstream objects can throw exceptions:
        configFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            if (configFile.is_open()) {
                std::string line;
                while (std::getline(configFile, line)) {
                    int location = line.find('=');
                    configValues[line.substr(0, location)] = line.substr(location + 1);
                }
                if (found) {
                    m.unlock();
                }
                return true;
            }
            if (found) {
                m.unlock();
            }
            return false;
        }
        catch (std::ifstream::failure &e) {
            std::cout << "ERROR::CONFIG::" << FilePath << "::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
            if (found) {
                m.unlock();
            }
            return false;
        }
    }

    bool Config::writeConfig() {
        bool found = false;
        if (std::find(configFiles.begin(), configFiles.end(), FilePath) == configFiles.end()) {
            configFiles.push_back(FilePath);
        } else {
            found = true;
            m.lock();
        }
        std::ofstream configFile;
        std::stringstream ss;

        configFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try {
            if (configFile.is_open()) {
                for (auto &a : configValues) {
                    ss << a.first << "=" << a.second << std::endl;
                }
                configFile << ss.str();
                if (found) {
                    m.unlock();
                }
                return true;
            }
            if (found) {
                m.unlock();
            }
            return false;
        }
        catch (std::ifstream::failure &e) {
            std::cout << "ERROR::CONFIG::" << FilePath << "::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
            if (found) {
                m.unlock();
            }
            return false;
        }
    }

    std::unordered_map<std::string, std::string> &Config::getConfig() {
        return configValues;
    }
}
