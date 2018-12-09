#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <sci/Enums.hpp>
#include <sci/Macros.hpp>

class Application;

class Manager
{
public:
    virtual ~Manager() = default;

    void initialize();
    void terminate();

protected:
    Manager(Application& application);
    Manager(Manager&&) = delete;
    Manager(const Manager&) = delete;
    Manager& operator=(Manager&&) = delete;
    Manager& operator=(const Manager&) = delete;

    virtual void on_initialize();
    virtual void on_terminate();

    Application& get_application() const;

private:
    Application& m_application;
};

#endif // MANAGER_HPP
