#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _fixedPointVal(0) {
};

Fixed::Fixed(const int val) {
    float tmp = val * (1 << this->_fractionalBitsNb);
    this->_fixedPointVal = int(tmp);
}

Fixed::Fixed(const float val) {
    float tmp = roundf(val * (1 << this->_fractionalBitsNb));
    this->_fixedPointVal = int(tmp);
}

Fixed::Fixed(Fixed const &src) {
    *this = src;
};

Fixed::~Fixed() {
};


int             Fixed::getRawBits() const {
    return this->_fixedPointVal;
}

void            Fixed::setRawBits(int const raw) {
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
    if (this != &rhs)
        this->_fixedPointVal = rhs.getRawBits();
    return *this;
}

// comparison operators
bool            Fixed::operator>(Fixed const &rhs) const {
    return this->_fixedPointVal > rhs._fixedPointVal;
}
bool            Fixed::operator<(Fixed const &rhs) const {
    return this->_fixedPointVal < rhs._fixedPointVal;
}
bool            Fixed::operator>=(Fixed const &rhs) const {
    return this->_fixedPointVal >= rhs._fixedPointVal;
}
bool            Fixed::operator<=(Fixed const &rhs) const {
    return this->_fixedPointVal <= rhs._fixedPointVal;
}
bool            Fixed::operator==(Fixed const &rhs) const {
    return this->_fixedPointVal == rhs._fixedPointVal;
}
bool            Fixed::operator!=(Fixed const &rhs) const {
    return this->_fixedPointVal != rhs._fixedPointVal;
}


// arithmetic operators
Fixed           Fixed::operator+() const {
    return  Fixed(this->toFloat());
}
Fixed           Fixed::operator-() const {
    return  Fixed(- this->toFloat());
}
Fixed           Fixed::operator+(Fixed const &rhs) const {
    return  Fixed(this->toFloat() + rhs.toFloat());
}
Fixed           Fixed::operator-(Fixed const &rhs) const {
    return  Fixed(this->toFloat() - rhs.toFloat());
}
Fixed           Fixed::operator*(Fixed const &rhs) const {
    return  Fixed(this->toFloat() * rhs.toFloat());
}
Fixed           Fixed::operator/(Fixed const &rhs) const {
    return  Fixed(this->toFloat() / rhs.toFloat());
}

// increment/decrement operators
Fixed&  Fixed::operator++() {
    ++(this->_fixedPointVal);
    return *this;
}
Fixed&  Fixed::operator--() {
    --(this->_fixedPointVal);
    return *this;
}
Fixed   Fixed::operator++(int) {
    Fixed res(*this);
    ++(*this);
    return res;
}
Fixed   Fixed::operator--(int) {
    Fixed res(*this);
    --(*this);
    return res;
}

// min max
Fixed const  &Fixed::min(Fixed const &lhs, Fixed const &rhs) {
    if (lhs.toFloat() <= rhs.toFloat())
        return lhs;
    return rhs;
}
Fixed        &Fixed::min(Fixed &lhs, Fixed &rhs) {
    if (lhs.toFloat() <= rhs.toFloat())
        return lhs;
    return rhs;
}
Fixed const  &Fixed::max(Fixed const &lhs, Fixed const &rhs) {
    if (lhs.toFloat() >= rhs.toFloat())
        return lhs;
    return rhs;
}
Fixed        &Fixed::max(Fixed &lhs, Fixed &rhs) {
    if (lhs.toFloat() >= rhs.toFloat())
        return lhs;
    return rhs;
}

std::ostream    &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
}

const int Fixed::_fractionalBitsNb = 8;
