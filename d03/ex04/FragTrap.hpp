#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &src);
        ~FragTrap();

        FragTrap    &operator=(FragTrap const &rhs);
        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);

        void        vaulthunter_dot_exe(std::string const & target);

        void        KickHimWhileHesUp(std::string const & target);
        void        RopeADerp(std::string const & target);
        void        FloatLikeaBee(std::string const & target);
        void        TheThirdDegree(std::string const & target);
        void        CrisisManagement(std::string const & target);
    private:
        void        announce(bool die);
        void        attackText(std::string const & text, std::string const & target, int damage);
};

typedef void (FragTrap::*attackFunc)(std::string const & target);
struct FuncPtrStruct {
    std::string key;
    attackFunc func;
};

#endif
