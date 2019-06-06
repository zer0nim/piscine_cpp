#include "NinjaTrap.hpp"

# include <iostream>
# include <cstdlib>

NinjaTrap::NinjaTrap(): ClapTrap(60, 60, 120, 120, 1, "noname", 60, 5, 0) {
        announce(false);
};

NinjaTrap::NinjaTrap(std::string name): ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0) {
        announce(false);
};

NinjaTrap::NinjaTrap(NinjaTrap const &src) {
    *this = src;
};

NinjaTrap::~NinjaTrap() {
    announce(true);
};

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs) {
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

void        NinjaTrap::attackText(std::string const & text, std::string const & target, int damage) {
    std::cout << "NinjaTrap: " << this->_name << " attacks " << target \
        << " with \"" << text << "\" attack";
    if (damage != -1)
        std::cout << ", causing " << damage << " points of damage !";
    std::cout << std::endl;
}

void        NinjaTrap::rangedAttack(std::string const & target) {
    std::cout << "from NinjaTrap      ";
    ClapTrap::rangedAttack(target);
}

void        NinjaTrap::meleeAttack(std::string const & target) {
    std::cout << "from NinjaTrap      ";
    ClapTrap::meleeAttack(target);
}

void        NinjaTrap::announce(bool die) {
    if (die)
        std::cout << "__NinjaTrap: " << this->_name << " die:    " << std::endl;
    else
        std::cout << "++NinjaTrap: " << this->_name << " born:   " << std::endl;
}

void        funnyReference(std::string const & target) {
    std::string funnySentences[] = {
        "Beat it, fleshbag! / Eat it, fleshbag! [citation needed]",
        "HaHA!!!",
        "Pincer Attack!",
        "Punch punch! Fight!",
        "Target disassembled.",
        "Viva La Robolution!",
        "Shoryuken!"
    };
    int len = (sizeof(funnySentences)/sizeof(*funnySentences));
    std::cout << "Hey " << target << "! " << funnySentences[std::rand() % len] << std::endl;
}

void        NinjaTrap::ninjaShoebox(NinjaTrap const & target) {
    funnyReference(target.getName());
}
void        NinjaTrap::ninjaShoebox(FragTrap const & target) {
    funnyReference(target.getName());
}
void        NinjaTrap::ninjaShoebox(ScavTrap const & target) {
    funnyReference(target.getName());
}
