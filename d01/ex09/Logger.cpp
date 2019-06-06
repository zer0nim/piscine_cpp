#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>
#include <iomanip>

typedef void (Logger::*logFunc)(std::string const & target) const;
struct FuncPtrStruct {
    std::string key;
    logFunc func;
};

Logger::Logger(std::string logFileName): _logFileName(logFileName) {
};

Logger::~Logger() {
};

void    Logger::logToConsole(std::string const & message) const {
    std::cout << message << std::endl;
}

void    Logger::logToFile(std::string const & message) const {
    std::ofstream   ofs;
    ofs.open(this->_logFileName, std::ofstream::out | std::ofstream::app);

    if (!ofs)
    {
        std::cerr << "Error opening file !" << std::endl;
        return ;
    }
    ofs << message;
    ofs.close();
}

std::string Logger::makeLogEntry(std::string const & message) const {
    std::stringstream   ss;
    time_t              rawtime = time(nullptr);
    struct tm           *tm = localtime(&rawtime);

    ss << "[" << tm->tm_year + 1900 \
                << std::setw(2) << std::setfill('0') << tm->tm_mon + 1 \
                << std::setw(2) << std::setfill('0') << tm->tm_mday \
                << "_" << std::setw(2) << std::setfill('0') << tm->tm_hour \
                << std::setw(2) << std::setfill('0') << tm->tm_min \
                << std::setw(2) << std::setfill('0') << tm->tm_sec << "]";
    ss << " " << message << std::endl;
    return ss.str();
}

void    Logger::log(std::string const & dest, std::string const & message) const {
    FuncPtrStruct logsFuncts[] = {
        {"logToConsole", &Logger::logToConsole},
        {"logToFile", &Logger::logToFile}
    };

    logFunc func = NULL;
    int len = (sizeof(logsFuncts)/sizeof(*logsFuncts));
    for (int i = 0; i < len; ++i) {
        if (logsFuncts[i].key.compare(dest) == 0) {
            func = logsFuncts[i].func;
            break;
        }
    }

    if (func != NULL)
        (this->*func)(makeLogEntry(message));
    else
        std::cerr << "Error ! log dest: \"" << dest << "\" not recognized" << std::endl;
}
