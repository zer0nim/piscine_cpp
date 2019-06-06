#include "Enemy.hpp"

int     randomSpeed() {
    int min = 2;
    int max = 5;

    return (rand() % (max - min)) + min;
}

Enemy::Enemy(): AMovable() {
    _collidable = true;
    _shape = Shape(3, 2, '#');
    _speed = randomSpeed();
}

Enemy::Enemy(Pos pos): AMovable(pos) {
    _collidable = true;
    _shape = Shape(3, 2, '#');
    _speed = randomSpeed();
}

Enemy::Enemy(Enemy const &src) {
    *this = src;
}

Enemy::~Enemy() {
}

Enemy &Enemy::operator=(Enemy const &rhs) {
    if (this != &rhs)
        ;
    return *this;
}

void Enemy::update(const EventManager &event_manager, AEntity *entities, AEntity &player) {
    _velocity.setY(-1);
    move();
    (void)event_manager;
    (void)entities;
	(void)player;
}
