#include "Application.hpp"

#include <sci/Logger.hpp>
#include <sci/Timer.hpp>

Application::Application()
{
    m_managers[ManagerType::Logger] = new Logger(*this);
    m_managers[ManagerType::Timer] = new Timer(*this);

    for (auto manager : m_managers) {
        manager->initialize();
    }
}

Application::~Application()
{
    for (auto& manager : m_managers) {
        manager->terminate();
        delete manager;
        manager = nullptr;
    }
}
