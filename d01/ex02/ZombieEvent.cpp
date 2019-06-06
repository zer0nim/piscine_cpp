#include "ZombieEvent.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <random>

ZombieEvent::ZombieEvent() : _type("default") {
};

ZombieEvent::~ZombieEvent() {
};

void    ZombieEvent::setZombieType(std::string type) {
    this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name) {
    return new Zombie(this->_type, name);
}

void ZombieEvent::randomChump() {
    std::string zombNames[] = {"Doomstrike", "Stonefigure", "Tombboy", "Umbraface", "Plagueghoul", "Tanglebeing", "Shadowghoul"};

    // random value management
    int nbItem = (sizeof(zombNames)/sizeof(zombNames[0]));
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<int> choose(0, nbItem -1);

    std::string randomName = zombNames[choose(engine)];

    Zombie zomb = Zombie(this->_type, randomName);
    zomb.announce();
}
