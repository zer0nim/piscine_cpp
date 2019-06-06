#include "ScavTrap.hpp"

# include <iostream>
# include <cstdlib>

ScavTrap::ScavTrap(): ClapTrap(100, 100, 50, 50, 1, "noname", 15, 20, 3) {
        announce(false);
};

ScavTrap::ScavTrap(std::string name): ClapTrap(100, 100, 50, 50, 1, name, 15, 20, 3) {
        announce(false);
};

ScavTrap::ScavTrap(ScavTrap const &src) {
    *this = src;
};

ScavTrap::~ScavTrap() {
    announce(true);
};

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
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

void        ScavTrap::attackText(std::string const & text, std::string const & target, int damage) {
    std::cout << "ScavTrap: " << this->_name << " attacks " << target \
        << " with \"" << text << "\" attack";
    if (damage != -1)
        std::cout << ", causing " << damage << " points of damage !";
    std::cout << std::endl;
}

void        ScavTrap::announce(bool die) {
    if (die)
        std::cout << "__ScavTrap: " << this->_name << " die" << std::endl;
    else
        std::cout << "++ScavTrap" << this->_name << " born" << std::endl;
}

void        ScavTrap::challengeNewcomer(std::string const & target) {
    std::string challengeSentences[] = {
        "You versus me! Me versus you! Either way!",
        "I will prove to you my robotic superiority!",
        "Dance battle! Or, you know... regular battle.",
        "Man versus machine! Very tiny streamlined machine!",
        "Care to have a friendly duel?"
    };
    int len = (sizeof(challengeSentences)/sizeof(*challengeSentences));
    std::cout << "Hey " << target << "! " << challengeSentences[std::rand() % len] << std::endl;
}
