#include "Enemy.hpp"

#include <iostream>

Enemy::Enemy() {
};

Enemy::Enemy(int hp, std::string const &type) \
: _hp(hp), _type(type) {

}

Enemy::Enemy(Enemy const &src) {
    *this = src;
};

Enemy::~Enemy() {
};

Enemy &Enemy::operator=(Enemy const &rhs) {
    if (this != &rhs) {
        _hp = rhs.getHP();
        _type = rhs.getType();
    }
    return *this;
}

std::string     Enemy::getType() const { return _type; }
int             Enemy::getHP() const { return _hp; }

void            Enemy::takeDamage(int damage) {
    _hp = _hp - damage > 0 ? _hp - damage : 0;
}
