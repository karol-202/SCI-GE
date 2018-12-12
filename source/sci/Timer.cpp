#include "Timer.hpp"

#include <sci/Application.hpp>
#include <sci/Logger.hpp>

Timer::Timer(Application& application)
    : Manager(application)
{
    MANAGER_LOG("Initialize Timer");
}

float Timer::get_delta_time()
{
    const auto now = m_high_resolution_clock.now();
    const auto duration = std::chrono::duration<float>(now - m_start_time).count();
    m_start_time = now;

    return duration;
}

void Timer::on_initialize()
{
    m_start_time = m_high_resolution_clock.now();
}
