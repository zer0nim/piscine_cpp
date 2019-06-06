#include "PowerFist.hpp"

#include <iostream>

PowerFist::PowerFist(): AWeapon("Power Fist", 8, 50) {
};

PowerFist::PowerFist(PowerFist const &src) {
    *this = src;
};

PowerFist::~PowerFist() {
};

PowerFist &PowerFist::operator=(PowerFist const &rhs) {
    if (this != &rhs) {
        _name = rhs.getName();
        _apcost = rhs.getAPCost();
        _damage = rhs.getDamage();
    }
    return *this;
}

void    PowerFist::attack() const {
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
