#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class	ZombieHorde {
    public:
        ZombieHorde(int N);
        ~ZombieHorde();
        void    announce();
    private:
        Zombie  *_zombies;
        int     N;
};

#endif