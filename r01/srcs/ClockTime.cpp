#include "ClockTime.hpp"

clock_t     ClockTime::_old = std::clock();
clock_t     ClockTime::_time = std::clock();
double      ClockTime::deltaTime = 0;

ClockTime::ClockTime() {
}

ClockTime::ClockTime(ClockTime const &src) {
    *this = src;
}

ClockTime::~ClockTime() {
}

ClockTime &ClockTime::operator=(ClockTime const &rhs) {
    if (this != &rhs)
        ;
    return *this;
}

double  ClockTime::curentTime() {
    return std::clock() / (double)CLOCKS_PER_SEC;
}

double  ClockTime::updateDeltaTime() {
    ClockTime::_old = ClockTime::_time;
    ClockTime::_time = std::clock();
    ClockTime::deltaTime = (ClockTime::_time - ClockTime::_old) / (double)CLOCKS_PER_SEC;
    return ClockTime::deltaTime;
}
