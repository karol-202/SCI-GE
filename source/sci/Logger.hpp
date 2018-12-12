#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <sci/Manager.hpp>

class Logger final
    : public Manager
{
public:
    Logger(Application& application);
    virtual ~Logger() = default;

    MANAGER_STATIC_GET_TYPE(ManagerType::Logger)

    void log(std::string& msg) const;
    void log(const std::string& path, int line, const std::string& function, const std::string& msg) const;

protected:
private:
};

#endif // !LOGGER_HPP
