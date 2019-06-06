#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy {
    public:
        Enemy(int hp, std::string const &type);
        Enemy(Enemy const &src);
        virtual ~Enemy();

        Enemy &operator=(Enemy const &rhs);

        int             getHP() const;
        std::string     getType() const;

        virtual void takeDamage(int damage);
    protected:
        Enemy();
        int         _hp;
        std::string _type;
};

#endif
