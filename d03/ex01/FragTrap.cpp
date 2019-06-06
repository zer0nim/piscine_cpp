#include "FragTrap.hpp"

# include <iostream>
# include <cstdlib>

bool FragTrap::_runSrandOnce = false;

FragTrap::FragTrap() : _hitPoints(100), _maxHitPoints(100), \
    _energyPoints(100), _maxEnergyPoints(100), _level(1), _name("noname"), \
    _rangedAttackDamage(20), _meleeAttackDamage(30), _armorDamageReduction(5)
{
        // call srand only on the first instance
        if (!FragTrap::_runSrandOnce) {
            FragTrap::_runSrandOnce = true;
            srand(time(NULL));
        }
        announce(false);
};

FragTrap::FragTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), \
    _energyPoints(100), _maxEnergyPoints(100), _level(1), _name(name), \
    _rangedAttackDamage(20), _meleeAttackDamage(30), _armorDamageReduction(5)
{
        // call srand only on the first instance
        if (!FragTrap::_runSrandOnce) {
            FragTrap::_runSrandOnce = true;
            srand(time(NULL));
        }
        announce(false);
};

FragTrap::FragTrap(FragTrap const &src) {
    *this = src;
};

FragTrap::~FragTrap() {
    announce(true);
};

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
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

void        FragTrap::announce(bool die) {
    std::string announceSentences[] = {
        "Hey everybody! Check out my package!",
        "Let's get this party started!",
        "Glitching weirdness is a term of endearment, right?",
        "Recompiling my combat code!",
        "This time it'll be awesome, I promise!",
        "Look out everybody! Things are about to get awesome!"
    };
    std::string dieSentences[] = {
        "I'll die the way I lived: annoying!",
        "I bet your mom could do better!",
        "Oh yeah? Well, uh... yeah.",
        "Good thing I don't have a soul!",
        "Robot down!",
        "I have many regrets!"
    };

    if (die)
        std::cout << "__FragTrap: " << this->_name << " die:    " << dieSentences[std::rand() % 6] << std::endl;
    else
        std::cout << "++FragTrap: " << this->_name << " born:   " << announceSentences[std::rand() % 6] << std::endl;
}

void        FragTrap::setHitPoints(int hitPoints) {
    if (hitPoints > this->_maxHitPoints)
        hitPoints = this->_maxHitPoints;
    else if (hitPoints < 0)
        hitPoints = 0;
    this->_hitPoints = hitPoints;
}

void        FragTrap::setEnergyPoints(int energyPoints) {
    if (energyPoints > this->_maxEnergyPoints)
        energyPoints = this->_maxEnergyPoints;
    else if (energyPoints < 0)
        energyPoints = 0;
    this->_energyPoints = energyPoints;
}

void        FragTrap::setLevel(int level) {
    level = (level < 0) ? 0 : level;
    this->_level = level;
}

void        FragTrap::takeDamage(unsigned int amount) {
    int damage = amount - this->_armorDamageReduction;
    damage = (damage < 0)? 0 : damage;
    this->setHitPoints(this->_hitPoints - damage);

    std::cout << this->_name << " take " << amount \
        << " damage, causing " << damage \
        << " points of damage !" << std::endl;
}

void        FragTrap::beRepaired(unsigned int amount) {
    this->setHitPoints(this->_hitPoints + amount);

    std::cout << this->_name << " take " << amount \
        << " point of reparation" << std::endl;
}

void        FragTrap::attackText(std::string const & text, std::string const & target, int damage) {
    std::cout << this->_name << " attacks " << target \
        << " with \"" << text << "\" attack";
    if (damage != -1)
        std::cout << ", causing " << damage << " points of damage !";
    std::cout << std::endl;
}

void        FragTrap::rangedAttack(std::string const & target) {
    this->attackText("range", target, this->_rangedAttackDamage);
}

void        FragTrap::meleeAttack(std::string const & target) {
    this->attackText("melee", target, this->_meleeAttackDamage);
}

void        FragTrap::KickHimWhileHesUp(std::string const & target) {
    this->attackText("Kick Him While He's Up", target, -1);
}
void        FragTrap::RopeADerp(std::string const & target) {
    this->attackText("Rope-A-Derp", target, -1);
}
void        FragTrap::FloatLikeaBee(std::string const & target) {
    this->attackText("Float Like a Bee", target, -1);
}
void        FragTrap::TheThirdDegree(std::string const & target) {
    this->attackText("The Third Degree", target, -1);
}
void        FragTrap::CrisisManagement(std::string const & target) {
    this->attackText("Crisis Management", target, -1);
}

void        FragTrap::vaulthunter_dot_exe(std::string const & target) {
    int cost = 25;
    if (this->_energyPoints - cost >= 0) {
        this->setEnergyPoints(this->_energyPoints - cost);

        const FuncPtrStruct attacks[] = {
            {"KickHimWhileHesUp", &FragTrap::KickHimWhileHesUp},
            {"RopeADerp", &FragTrap::RopeADerp},
            {"FloatLikeaBee", &FragTrap::FloatLikeaBee},
            {"TheThirdDegree", &FragTrap::TheThirdDegree},
            {"CrisisManagement", &FragTrap::CrisisManagement}
        };

        int len = (sizeof(attacks)/sizeof(*attacks));
        attackFunc func = attacks[std::rand() % len].func;
        (this->*func)(target);
    } else {
        std::string emptyEnergySentences[] = {
            "Who needs energy anyway, am I right?",
            "Dangit, I'm out!",
            "Energy reserves are spent!",
            "Crap, no more shots left!",
            "Hnngh! Empty!"
        };
        int len = (sizeof(emptyEnergySentences)/sizeof(*emptyEnergySentences));
        std::cout << emptyEnergySentences[std::rand() % len] << std::endl;
    }
}

int         FragTrap::getHitPoints() const { return this->_hitPoints; }
int         FragTrap::getMaxHitPoints() const { return this->_maxHitPoints; }
int         FragTrap::getEnergyPoints() const { return this->_energyPoints; }
int         FragTrap::getMaxEnergyPoints() const { return this->_maxEnergyPoints; }
int         FragTrap::getLevel() const { return this->_level; }
std::string FragTrap::getName() const { return this->_name; }
int         FragTrap::getRangedAttackDamage() const { return this->_rangedAttackDamage; }
int         FragTrap::getMeleeAttackDamage() const { return this->_meleeAttackDamage; }
int         FragTrap::getArmorDamageReduction() const { return this->_armorDamageReduction; }