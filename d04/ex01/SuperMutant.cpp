#include "SuperMutant.hpp"

#include <iostream>

SuperMutant::SuperMutant(): Enemy(170, "Super Mutant") {
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
};

SuperMutant::SuperMutant(SuperMutant const &src) {
    *this = src;
};

SuperMutant::~SuperMutant() {
    std::cout << "Aaargh ..." << std::endl;
};

SuperMutant &SuperMutant::operator=(SuperMutant const &rhs) {
    if (this != &rhs) {
        _hp = rhs.getHP();
        _type = rhs.getType();
    }
    return *this;
}

void SuperMutant::takeDamage(int damage) {
    Enemy::takeDamage(damage - 3 > 0 ? damage - 3 : 0);
}
