#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _fixedPointVal(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
};

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int     Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointVal;
}
void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointVal = raw;
}

Fixed   &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointVal = rhs.getRawBits();
    return *this;
}

const int Fixed::_fractionalBitsNb = 8;
