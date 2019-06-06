#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character {
    public:
        Character(std::string const &name);
        Character(Character const &src);
        ~Character();

        Character &operator=(Character const &rhs);

        void        recoverAP();
        void        equip(AWeapon* wp);
        void        attack(Enemy* enemy);

        std::string     getName() const;
        int             getAp() const;
        AWeapon         *getWp() const;
    protected:
        Character();
    private:
        std::string _name;
        int         _ap;
        AWeapon     *_wp;

};

std::ostream    &operator<<(std::ostream &o, Character const &i);

#endif
