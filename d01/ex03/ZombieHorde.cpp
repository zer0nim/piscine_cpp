#include "ZombieHorde.hpp"
#include <string>
#include <random>

ZombieHorde::ZombieHorde(int N): N(N) {
    std::string zombNames[] = {"Doomstrike", "Stonefigure", "Tombboy", "Umbraface", "Plagueghoul", "Tanglebeing", "Shadowghoul"};
    this->_zombies = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        // random value management
        int nbItem = (sizeof(zombNames)/sizeof(zombNames[0]));
        std::random_device seed;
        std::mt19937 engine(seed());
        std::uniform_int_distribution<int> choose(0, nbItem -1);

        std::string randomName = zombNames[choose(engine)];

        this->_zombies[i].setName(randomName);
    }
};

ZombieHorde::~ZombieHorde() {
    delete [] this->_zombies;
};

void    ZombieHorde::announce() {
    for (int i = 0; i < this->N; i++)
        this->_zombies[i].announce();
}