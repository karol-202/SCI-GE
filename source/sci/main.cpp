#include <sci/Application.hpp>
#include <sci/Macros.hpp>

int main(int argc, char* argv[])
{
    UNUSED(argc)
    UNUSED(argv)

    Application application;
    application.main_loop();

    return 0;
}