#include "Human.hpp"

Human::Human() : _brain(new Brain) {
};

Human::~Human() {
    delete _brain;
};

std::string Human::identify() const {
	return this->_brain->identify();
}

Brain const &Human::getBrain() const { return *(this->_brain); }