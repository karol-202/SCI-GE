#ifndef ENUMS_HPP
#define ENUMS_HPP

namespace ManagerType
{
    enum Enum {
        Logger = 0,
        Timer,
        //Input,
        Renderer,
        __MAX,
    };
};

namespace MainLoopStatus {
    enum Enum {
        SUCCESS = 0,
        CLOSE,
        ERROR,
    };
}

#endif // !ENUMS_HPP
