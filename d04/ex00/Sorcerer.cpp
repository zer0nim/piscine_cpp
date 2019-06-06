#include "Sorcerer.hpp"

# include <iostream>

Sorcerer::Sorcerer() {
};

Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title) {
    std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src) {
    *this = src;
};

Sorcerer::~Sorcerer() {
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
};

Sorcerer &Sorcerer::operator=(Sorcerer const &rhs) {
    if (this != &rhs) {
        _name = rhs.getName();
        _title = rhs.getTitle();
    }
    return *this;
}

void        Sorcerer::polymorph(Victim const &v) const {
    v.getPolymorphed();
}

std::ostream    &operator<<(std::ostream &o, Sorcerer const &i) {
    o << "I am " << i.getName() << ", " << i.getTitle() << ", and I like ponies !" << std::endl;
    return o;
}

std::string Sorcerer::getName() const { return _name; }
std::string Sorcerer::getTitle() const { return _title; }
