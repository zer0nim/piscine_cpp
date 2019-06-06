#ifndef CLOCKTIME_HPP
# define CLOCKTIME_HPP

# include <ctime>

class ClockTime {
    public:
        static  double  curentTime();
        static  double  updateDeltaTime();

        static  double  deltaTime;
    private:
        ClockTime();
        ClockTime(ClockTime const &src);
        ~ClockTime();

        ClockTime &operator=(ClockTime const &rhs);

        static  clock_t _time;
        static  clock_t _old;
};

#endif