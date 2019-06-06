#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <string>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap: virtual public ClapTrap {
    public:
        NinjaTrap();
        NinjaTrap(std::string name);
        NinjaTrap(NinjaTrap const &src);
        ~NinjaTrap();

        NinjaTrap    &operator=(NinjaTrap const &rhs);
        void        rangedAttack(std::string const & target);
        void        meleeAttack(std::string const & target);

        void        ninjaShoebox(NinjaTrap const & target);
        void        ninjaShoebox(FragTrap const & target);
        void        ninjaShoebox(ScavTrap const & target);
    private:
        void        announce(bool die);
        void        attackText(std::string const & text, std::string const & target, int damage);
};

#endif
