#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"

class   ZombieEvent {
    public:
        ZombieEvent();
        ~ZombieEvent();
        void    setZombieType(std::string type);
        Zombie* newZombie(std::string name);
        void    randomChump();
    private:
        std::string _type;
};

#endif