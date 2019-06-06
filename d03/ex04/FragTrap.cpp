#include "FragTrap.hpp"

# include <iostream>
# include <cstdlib>

FragTrap::FragTrap() : ClapTrap(100, 100, 100, 100, 1, "noname", 20, 30, 5) {
        announce(false);
};

FragTrap::FragTrap(std::string name) : ClapTrap(100, 100, 100, 100, 1, name, 20, 30, 5) {
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

void        FragTrap::attackText(std::string const & text, std::string const & target, int damage) {
    std::cout << "FragTrap: " << this->_name << " attacks " << target \
        << " with \"" << text << "\" attack";
    if (damage != -1)
        std::cout << ", causing " << damage << " points of damage !";
    std::cout << std::endl;
}

void        FragTrap::rangedAttack(std::string const & target) {
    std::cout << "from FragTrap      ";
    ClapTrap::rangedAttack(target);
}

void        FragTrap::meleeAttack(std::string const & target) {
    std::cout << "from FragTrap      ";
    ClapTrap::meleeAttack(target);
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
