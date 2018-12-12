#include "Manager.hpp"

Manager::Manager(Application& application)
    : m_application(application)
{
}

void Manager::initialize()
{
    on_initialize();
}

void Manager::terminate()
{
    on_terminate();
}

void Manager::on_initialize()
{
}

void Manager::on_terminate()
{
}

Application& Manager::get_application() const
{
    return m_application;
}
