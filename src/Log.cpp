//
// Created by andre on 11/22/2020.
//

#include "Log.h"

namespace ClockworkEngine {
    const std::string &Log::filePath = "Logs/log.txt";
    short Log::count = 0;
    std::mutex Log::m;

    void Log::writeError(const std::string &message) {
        std::ofstream output;
        output.exceptions(std::ofstream::failbit | std::ofstream::badbit);

        try {
#ifndef DEBUG
            std::cout << message << std::endl;
#endif
            m.lock();
            output.open(filePath, std::ios::app);
            output << message;
            output.close();
            m.unlock();
            count = 0;
        } catch (std::ofstream::failure &e) {
            output.close();
            m.unlock();
            if(count < 50){
                writeError(e.what());
                ++count;
            }else{
                throw e;
            }
        }
    }
}