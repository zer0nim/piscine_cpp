#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"

class AssaultTerminator: public ISpaceMarine {
    public:
        AssaultTerminator();
        AssaultTerminator(AssaultTerminator const &src);
        virtual ~AssaultTerminator();

        AssaultTerminator &operator=(AssaultTerminator const &rhs);

        virtual ISpaceMarine*   clone() const;
        virtual void            battleCry() const;
        virtual void            rangedAttack() const;
        virtual void            meleeAttack() const;
    private:
};

#endif