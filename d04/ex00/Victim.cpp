#include "Victim.hpp"

# include <iostream>

Victim::Victim() {
};

Victim::Victim(std::string name): _name(name) {
    std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::Victim(Victim const &src) {
    *this = src;
};

Victim::~Victim() {
    std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
};

Victim &Victim::operator=(Victim const &rhs) {
    if (this != &rhs) {
        _name = rhs.getName();
    }
    return *this;
}

void        Victim::getPolymorphed() const {
    std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream    &operator<<(std::ostream &o, Victim const &i) {
    o << "I'm " << i.getName() << " and I like otters !" << std::endl;
    return o;
}

std::string Victim::getName() const { return _name; }
