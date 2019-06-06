#include "Logger.hpp"
#include <iostream>

int main(void)
{
    Logger logger = Logger("output");
    logger.log("logToConsole", "Hey! what's up ?");
    std::cout << "-------" << std::endl;
    logger.log("logToFile", "Hey! what's up ?");
    std::cout << "-------" << std::endl;
    logger.log("vffdvdfbdfbxf", "Hey! what's up ?");
    return 0;
}
