//
// Created by andre on 11/22/2020.
//

#ifndef CLOCKWORKENGINE_LOG_H
#define CLOCKWORKENGINE_LOG_H

#include <fstream>
#include <iostream>
#include <mutex>
#include <vector>

namespace ClockworkEngine {

    class Log {
    private:
        static std::mutex m;
        static const std::string & filePath;
        static short count;
    public:
        static void writeError(const std::string& message);
    };

}


#endif //CLOCKWORKENGINE_LOG_H
