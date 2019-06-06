#include "Peon.hpp"

# include <iostream>

Peon::Peon() {
};

Peon::Peon(std::string name): Victim(name) {
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &src) {
    *this = src;
};

Peon::~Peon() {
    std::cout << "Bleuark..." << std::endl;
};


Peon &Peon::operator=(Peon const &rhs) {
    if (this != &rhs)
        _name = rhs.getName();
    return *this;
}

void        Peon::getPolymorphed() const {
    std::cout << _name << " has been turned into a pink pony !" << std::endl;
}
