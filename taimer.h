#ifndef TAIMER_H
#define TAIMER_H

#include <chrono>

class Taimer
{
    std::chrono::time_point<std::chrono::system_clock> _start, _end;
    float* elapsed_seconds;

public:
    Taimer(float* elapsed_seconds);

    void start();
    void pause();
    void stop();

    ~Taimer();

};

#endif // TAIMER_H
