#include "Brain.hpp"
#include <sstream>
#include <string>

Brain::Brain() {
};

Brain::~Brain() {
};

std::string	Brain::identify() const {
    std::stringstream ss;
	ss << this;
	return ss.str();
}