#ifndef STATUS_H
#define STATUS_H
namespace Homm {
    enum class Status{
        // качество
        is_tired = 200, // усталый
        is_slept = 201, // сонный


        // процесс
        is_sleeping = 1100,
        is_working = 1101
    };
}
#endif // STATUS_H
