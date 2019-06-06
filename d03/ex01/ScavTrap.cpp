#include "ScavTrap.hpp"

# include <iostream>
# include <cstdlib>

bool ScavTrap::_runSrandOnce = false;

ScavTrap::ScavTrap() : _hitPoints(100), _maxHitPoints(100), \
    _energyPoints(50), _maxEnergyPoints(50), _level(1), _name("noname"), \
    _rangedAttackDamage(15), _meleeAttackDamage(20), _armorDamageReduction(3)
{
        // call srand only on the first instance
        if (!ScavTrap::_runSrandOnce) {
            ScavTrap::_runSrandOnce = true;
            srand(time(NULL));
        }
        announce(false);
};

ScavTrap::ScavTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), \
    _energyPoints(50), _maxEnergyPoints(50), _level(1), _name(name), \
    _rangedAttackDamage(15), _meleeAttackDamage(20), _armorDamageReduction(3)
{
        // call srand only on the first instance
        if (!ScavTrap::_runSrandOnce) {
            ScavTrap::_runSrandOnce = true;
            srand(time(NULL));
        }
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

void        ScavTrap::announce(bool die) {
    if (die)
        std::cout << "__ScavTrap: " << this->_name << " die:" << std::endl;
    else
        std::cout << "++ScavTrap" << this->_name << " born:    " << std::endl;
}

void        ScavTrap::setHitPoints(int hitPoints) {
    if (hitPoints > this->_maxHitPoints)
        hitPoints = this->_maxHitPoints;
    else if (hitPoints < 0)
        hitPoints = 0;
    this->_hitPoints = hitPoints;
}

void        ScavTrap::setEnergyPoints(int energyPoints) {
    if (energyPoints > this->_maxEnergyPoints)
        energyPoints = this->_maxEnergyPoints;
    else if (energyPoints < 0)
        energyPoints = 0;
    this->_energyPoints = energyPoints;
}

void        ScavTrap::setLevel(int level) {
    level = (level < 0) ? 0 : level;
    this->_level = level;
}

void        ScavTrap::takeDamage(unsigned int amount) {
    int damage = amount - this->_armorDamageReduction;
    damage = (damage < 0)? 0 : damage;
    this->setHitPoints(this->_hitPoints - damage);

    std::cout << this->_name << " take " << amount \
        << " damage, causing " << damage \
        << " points of damage !" << std::endl;
}

void        ScavTrap::beRepaired(unsigned int amount) {
    this->setHitPoints(this->_hitPoints + amount);

    std::cout << this->_name << " take " << amount \
        << " point of reparation" << std::endl;
}

void        ScavTrap::attackText(std::string const & text, std::string const & target, int damage) {
    std::cout << this->_name << " attacks " << target \
        << " with \"" << text << "\" attack";
    if (damage != -1)
        std::cout << ", causing " << damage << " points of damage !";
    std::cout << std::endl;
}

void        ScavTrap::rangedAttack(std::string const & target) {
    this->attackText("range", target, this->_rangedAttackDamage);
}

void        ScavTrap::meleeAttack(std::string const & target) {
    this->attackText("melee", target, this->_meleeAttackDamage);
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

int         ScavTrap::getHitPoints() const { return this->_hitPoints; }
int         ScavTrap::getMaxHitPoints() const { return this->_maxHitPoints; }
int         ScavTrap::getEnergyPoints() const { return this->_energyPoints; }
int         ScavTrap::getMaxEnergyPoints() const { return this->_maxEnergyPoints; }
int         ScavTrap::getLevel() const { return this->_level; }
std::string ScavTrap::getName() const { return this->_name; }
int         ScavTrap::getRangedAttackDamage() const { return this->_rangedAttackDamage; }
int         ScavTrap::getMeleeAttackDamage() const { return this->_meleeAttackDamage; }
int         ScavTrap::getArmorDamageReduction() const { return this->_armorDamageReduction; }