#include "Zombie.hpp"

Zombie::Zombie() : _type("default"), _name("noName") {
};

Zombie::Zombie(std::string type, std::string name) : _type(type), _name(name) {
};

Zombie::~Zombie() {
    std::cout << "Zombie: " << this->_name << " destroyed !" << std::endl;
};

void    Zombie::announce() const {
    std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiinnnssss..." << std::endl;
}

void        Zombie::setType(std::string type) { this->_type = type; }
void        Zombie::setName(std::string name) { this->_name = name; }
std::string Zombie::getType() const { return this->_type; }
std::string Zombie::getName() const { return this->_name; }