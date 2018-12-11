#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <sci/Manager.hpp>

class Timer final
    : public Manager
{
public:
    Timer(Application& application);
    virtual ~Timer() = default;

    MANAGER_STATIC_GET_TYPE(ManagerType::Timer)

    float get_delta_time();

protected:
    virtual void on_initialize() override;

private:
    std::chrono::high_resolution_clock m_high_resolution_clock;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time;
};

#endif // !TIMER_HPP
