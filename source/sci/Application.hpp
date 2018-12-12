#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <array>
#include <sci/Enums.hpp>

class Manager;

class Application final
{
public:
    Application();
    ~Application();

    MainLoopStatus::Enum main_loop();

    template<typename T>
    T& get_manager();

protected:

private:
    std::array<Manager*, ManagerType::__MAX> m_managers;
    MainLoopStatus::Enum m_status;
};

template<typename T>
inline T& Application::get_manager()
{
    auto manager = m_managers[T::get_type()];
    return static_cast<T&>(*manager);
}

#endif
