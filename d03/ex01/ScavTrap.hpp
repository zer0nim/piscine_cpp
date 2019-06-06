#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>

class ScavTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &src);
        ~ScavTrap();

        ScavTrap &operator=(ScavTrap const &rhs);
        void        challengeNewcomer(std::string const & target);
        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);

        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);

        int         getHitPoints() const;
        int         getMaxHitPoints() const;
        int         getEnergyPoints() const;
        int         getMaxEnergyPoints() const;
        int         getLevel() const;
        std::string getName() const;
        int         getRangedAttackDamage() const;
        int         getMeleeAttackDamage() const;
        int         getArmorDamageReduction() const;
    private:
        int         _hitPoints;
        int         _maxHitPoints;
        int         _energyPoints;
        int         _maxEnergyPoints;
        int         _level;
        std::string _name;
        int         _rangedAttackDamage;
        int         _meleeAttackDamage;
        int         _armorDamageReduction;

        void        setHitPoints(int hitPoints);
        void        setEnergyPoints(int energyPoints);
        void        setLevel(int level);

        void        announce(bool die);
        void        attackText(std::string const & text, std::string const & target, int damage);

        static bool _runSrandOnce;
};

#endif
