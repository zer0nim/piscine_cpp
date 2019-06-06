#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>

class FragTrap {
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &src);
        ~FragTrap();

        FragTrap &operator=(FragTrap const &rhs);
        void        vaulthunter_dot_exe(std::string const & target);
        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);

        void        KickHimWhileHesUp(std::string const & target);
        void        RopeADerp(std::string const & target);
        void        FloatLikeaBee(std::string const & target);
        void        TheThirdDegree(std::string const & target);
        void        CrisisManagement(std::string const & target);

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

typedef void (FragTrap::*attackFunc)(std::string const & target);
struct FuncPtrStruct {
    std::string key;
    attackFunc func;
};


#endif
