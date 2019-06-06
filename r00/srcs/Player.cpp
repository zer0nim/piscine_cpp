#include "Player.hpp"
#include "View.hpp"
#include <iostream>

Player::Player(): AMovable(Pos(View::width / 2, View::height - 3)) {
    _collidable = true;
    _shape = Shape(2, 2, 'V');
}

Player::Player(Player const &src) {
    *this = src;
}

Player::~Player() {
}

Player &Player::operator=(Player const &rhs) {
    if (this != &rhs)
        ;
    return *this;
}

void Player::update(const EventManager &event_manager, AEntity *entities, AEntity &player) {
    (void)player;
    (void)entities;
    (void)event_manager;

    if (event_manager.getHorizontAxis() != 0)
        _velocity.setX(event_manager.getHorizontAxis());

    if (event_manager.getVerticalAxis() != 0)
        _velocity.setY(event_manager.getVerticalAxis());

    move();
}
