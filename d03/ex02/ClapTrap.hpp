#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(int hitPoints, int maxHitPoints, int energyPoints, \
            int maxEnergyPoints, int level, std::string name, int rangedAttackDamage, \
            int meleeAttackDamage, int armorDamageReduction);
        ClapTrap(ClapTrap const &src);
        ~ClapTrap();

        ClapTrap &operator=(ClapTrap const &rhs);
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
    protected:
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
        virtual void    attackText(std::string const & text, std::string const & target, int damage);

        static bool _runSrandOnce;
};

#endif
