#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &src);
        ~ScavTrap();

        ScavTrap    &operator=(ScavTrap const &rhs);
        void        challengeNewcomer(std::string const & target);
    private:
        void        announce(bool die);
        void        attackText(std::string const & text, std::string const & target, int damage);
};

#endif
