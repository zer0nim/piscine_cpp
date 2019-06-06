#include "Character.hpp"

#include <iostream>

Character::Character(std::string const &name): _name(name), _ap(40), _wp(NULL) {
}

Character::Character(Character const &src) {
    *this = src;
};

Character::~Character() {
};

Character &Character::operator=(Character const &rhs) {
    if (this != &rhs) {
        _name = rhs.getName();
        _ap = rhs.getAp();
        _wp = rhs.getWp();
    }
    return *this;
}

void        Character::recoverAP() {
    _ap = _ap + 10 > 40 ? 40 : _ap + 10;
}
void        Character::equip(AWeapon* wp) {
    _wp = wp;
}
void        Character::attack(Enemy* enemy) {
    if (_wp != NULL) {
        if (_ap > 0 && _ap - _wp->getAPCost() >= 0) {
            std::cout << _name << " attacks " << enemy->getType() << " with a " << _wp->getName() << std::endl;
            _wp->attack();
            _ap -= _wp->getAPCost();
            enemy->takeDamage(_wp->getDamage());
            if (enemy->getHP() <= 0) {
                delete enemy;
            }
        } else {
            std::cout << "Not enought ap !" << std::endl;
        }
    }
}

std::string     Character::getName() const { return _name; }
int             Character::getAp() const { return _ap; }
AWeapon         *Character::getWp() const { return _wp; }

std::ostream    &operator<<(std::ostream &o, Character const &i) {
    if (i.getWp() != NULL)
        o << i.getName() << " has " << i.getAp() << " AP and wields a " << i.getWp()->getName() << std::endl;
    else
        o << i.getName() << " has " << i.getAp() << " AP and is unarmed" << std::endl;
    return o;
}
