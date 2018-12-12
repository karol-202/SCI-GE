#include "Logger.hpp"

#include <iostream>
#include <sci/Application.hpp>

Logger::Logger(Application& application)
    : Manager(application)
{
    MANAGER_LOG("Initialize Logger");
}

void Logger::log(std::string& msg) const
{
    std::cout << msg << std::endl;
}

void Logger::log(const std::string& path, int line, const std::string& function, const std::string& msg) const
{
    std::cout << path << ":" << std::to_string(line) << '\t' << function << '\t' << msg << std::endl;
}
