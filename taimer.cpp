#include "taimer.h"

Taimer::Taimer(float* elapsed_seconds)
{
    this->elapsed_seconds = elapsed_seconds;
}

void Taimer::start()
{
    this->_start = std::chrono::system_clock::now();
}

void Taimer::pause()
{
    this->_end = std::chrono::system_clock::now();
    *this->elapsed_seconds += 1e-3*std::chrono::duration_cast<std::chrono::milliseconds>
            (this->_end-this->_start).count();
}

void Taimer::stop()
{
    this->_end = std::chrono::system_clock::now();
    *this->elapsed_seconds = 1e-3*std::chrono::duration_cast<std::chrono::milliseconds>
            (this->_end-this->_start).count();
}

Taimer::~Taimer()
{

}

