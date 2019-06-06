#include "SuperTrap.hpp"

# include <iostream>
# include <cstdlib>

SuperTrap::SuperTrap(): ClapTrap(100, 100, 120, 120, 1, "noname", 60, 30, 5) {
        announce(false);
};

SuperTrap::SuperTrap(std::string name): ClapTrap(100, 100, 120, 120, 1, name, 60, 30, 5) {
        announce(false);
};

SuperTrap::SuperTrap(SuperTrap const &src) {
    *this = src;
};

SuperTrap::~SuperTrap() {
    announce(true);
};

SuperTrap &SuperTrap::operator=(SuperTrap const &rhs) {
    if (this != &rhs) {
        this->_hitPoints = rhs.getHitPoints();
        this->_maxHitPoints = rhs.getMaxHitPoints();
        this->_energyPoints = rhs.getEnergyPoints();
        this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
        this->_level = rhs.getLevel();
        this->_name = rhs.getName();
        this->_rangedAttackDamage = rhs.getRangedAttackDamage();
        this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
        this->_armorDamageReduction = rhs.getArmorDamageReduction();
    }
    return *this;
}

void        SuperTrap::attackText(std::string const & text, std::string const & target, int damage) {
    std::cout << "SuperTrap: " << this->_name << " attacks " << target \
        << " with \"" << text << "\" attack";
    if (damage != -1)
        std::cout << ", causing " << damage << " points of damage !";
    std::cout << std::endl;
}

void        SuperTrap::announce(bool die) {
    if (die)
        std::cout << "__SuperTrap: " << this->_name << " die:    " << std::endl;
    else
        std::cout << "++SuperTrap: " << this->_name << " born:   " << std::endl;
}

void        SuperTrap::rangedAttack(std::string const & target) {
    FragTrap::rangedAttack(target);
}

void        SuperTrap::meleeAttack(std::string const & target) {
    NinjaTrap::meleeAttack(target);
}