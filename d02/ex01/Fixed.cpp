#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _fixedPointVal(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int val) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointVal = val * (1 << this->_fractionalBitsNb);
}

Fixed::Fixed(const float val) {
    std::cout << "Float constructor called" << std::endl;
    float tmp = roundf(val * (1 << this->_fractionalBitsNb));
    this->_fixedPointVal = int(tmp);
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
};

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};


int             Fixed::getRawBits() const {
    return this->_fixedPointVal;
}

void            Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointVal = raw;
}

float           Fixed::toFloat( void ) const {
    return (float)this->_fixedPointVal / (1 << this->_fractionalBitsNb);
}

int             Fixed::toInt( void ) const {
    int     val = this->_fixedPointVal;
    val >>= this->_fractionalBitsNb;
    return val;
}

Fixed           &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointVal = rhs.getRawBits();
    return *this;
}

std::ostream    &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
}

const int Fixed::_fractionalBitsNb = 8;
