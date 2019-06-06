#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant: public Enemy {
    public:
        SuperMutant();
        SuperMutant(SuperMutant const &src);
        virtual ~SuperMutant();

        SuperMutant &operator=(SuperMutant const &rhs);

        virtual void takeDamage(int damage);
    private:
};

#endif