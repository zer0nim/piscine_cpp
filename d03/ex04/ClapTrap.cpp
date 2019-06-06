#include "ClapTrap.hpp"

# include <iostream>
# include <cstdlib>

bool ClapTrap::_runSrandOnce = false;

ClapTrap::ClapTrap() : _hitPoints(100), _maxHitPoints(100), \
    _energyPoints(50), _maxEnergyPoints(50), _level(1), _name("noname"), \
    _rangedAttackDamage(15), _meleeAttackDamage(20), _armorDamageReduction(3)
{
        std::cout << "-----------------Default called" << std::endl;
        // call srand only on the first instance
        if (!ClapTrap::_runSrandOnce) {
            ClapTrap::_runSrandOnce = true;
            srand(time(NULL));
        }
        announce(false);
};

ClapTrap::ClapTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), \
    _energyPoints(50), _maxEnergyPoints(50), _level(1), _name(name), \
    _rangedAttackDamage(15), _meleeAttackDamage(20), _armorDamageReduction(3)
{
        std::cout << "-----------------one string called" << std::endl;
        // call srand only on the first instance
        if (!ClapTrap::_runSrandOnce) {
            ClapTrap::_runSrandOnce = true;
            srand(time(NULL));
        }
        announce(false);
};

ClapTrap::ClapTrap(int hitPoints, int maxHitPoints, int energyPoints, \
    int maxEnergyPoints, int level, std::string name, int rangedAttackDamage, \
    int meleeAttackDamage, int armorDamageReduction) : \
    _hitPoints(hitPoints), _maxHitPoints(maxHitPoints), _energyPoints(energyPoints), \
    _maxEnergyPoints(maxEnergyPoints), _level(level), _name(name), \
    _rangedAttackDamage(rangedAttackDamage), _meleeAttackDamage(meleeAttackDamage), \
    _armorDamageReduction(armorDamageReduction)
{
        std::cout << "-----------------all param called" << std::endl;
        // call srand only on the first instance
        if (!ClapTrap::_runSrandOnce) {
            ClapTrap::_runSrandOnce = true;
            srand(time(NULL));
        }
        announce(false);
};

ClapTrap::ClapTrap(ClapTrap const &src) {
    *this = src;
};

ClapTrap::~ClapTrap() {
    announce(true);
};

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
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

void        ClapTrap::announce(bool die) {
    if (die)
        std::cout << "__ClapTrap: " << this->_name << " die" << std::endl;
    else
        std::cout << "++ClapTrap: " << this->_name << " born" << std::endl;
}

void        ClapTrap::setHitPoints(int hitPoints) {
    if (hitPoints > this->_maxHitPoints)
        hitPoints = this->_maxHitPoints;
    else if (hitPoints < 0)
        hitPoints = 0;
    this->_hitPoints = hitPoints;
}

void        ClapTrap::setEnergyPoints(int energyPoints) {
    if (energyPoints > this->_maxEnergyPoints)
        energyPoints = this->_maxEnergyPoints;
    else if (energyPoints < 0)
        energyPoints = 0;
    this->_energyPoints = energyPoints;
}

void        ClapTrap::setLevel(int level) {
    level = (level < 0) ? 0 : level;
    this->_level = level;
}

void        ClapTrap::takeDamage(unsigned int amount) {
    int damage = amount - this->_armorDamageReduction;
    damage = (damage < 0)? 0 : damage;
    this->setHitPoints(this->_hitPoints - damage);

    std::cout << this->_name << " take " << amount \
        << " damage, causing " << damage \
        << " points of damage !" << std::endl;
}

void        ClapTrap::beRepaired(unsigned int amount) {
    this->setHitPoints(this->_hitPoints + amount);

    std::cout << this->_name << " take " << amount \
        << " point of reparation" << std::endl;
}

void        ClapTrap::attackText(std::string const & text, std::string const & target, int damage) {
    std::cout << "ClapTrap: " << this->_name << " attacks " << target \
        << " with \"" << text << "\" attack";
    if (damage != -1)
        std::cout << ", causing " << damage << " points of damage !";
    std::cout << std::endl;
}

void        ClapTrap::rangedAttack(std::string const & target) {
    this->attackText("range", target, this->_rangedAttackDamage);
}

void        ClapTrap::meleeAttack(std::string const & target) {
    this->attackText("melee", target, this->_meleeAttackDamage);
}

int         ClapTrap::getHitPoints() const { return this->_hitPoints; }
int         ClapTrap::getMaxHitPoints() const { return this->_maxHitPoints; }
int         ClapTrap::getEnergyPoints() const { return this->_energyPoints; }
int         ClapTrap::getMaxEnergyPoints() const { return this->_maxEnergyPoints; }
int         ClapTrap::getLevel() const { return this->_level; }
std::string ClapTrap::getName() const { return this->_name; }
int         ClapTrap::getRangedAttackDamage() const { return this->_rangedAttackDamage; }
int         ClapTrap::getMeleeAttackDamage() const { return this->_meleeAttackDamage; }
int         ClapTrap::getArmorDamageReduction() const { return this->_armorDamageReduction; }