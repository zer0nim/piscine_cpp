#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

int main(void) {
    // Fixed a(-10);
    // Fixed b(42);
    // std::cout << "a: " << a.toFloat() << ", b: " << b.toFloat() << std::endl;
    // std::cout << std::endl << "comparison operators: " << std::endl;
    // std::cout << "a > b: " << std::boolalpha << (a > b) << std::endl;
    // std::cout << "a < b: " << std::boolalpha << (a < b) << std::endl;
    // std::cout << "a >= b: " << std::boolalpha << (a >= b) << std::endl;
    // std::cout << "a <= b: " << std::boolalpha << (a <= b) << std::endl;
    // std::cout << "a == b: " << std::boolalpha << (a == b) << std::endl;
    // std::cout << "a != b: " << std::boolalpha << (a != b) << std::endl;

    // std::cout << std::endl << "arithmetic operators: " << std::endl;
    // std::cout << "+a: " << (+a).toFloat() << std::endl;
    // std::cout << "-a: " << (-a).toFloat() << std::endl;
    // std::cout << "a + b: " << (a + b).toFloat() << std::endl;
    // std::cout << "a - b: " << (a - b).toFloat() << std::endl;
    // std::cout << "a * b: " << (a * b).toFloat() << std::endl;
    // std::cout << "a / b: " << (a / b).toFloat() << std::endl;

    // std::cout << std::endl << "increment/decrement operators: " << std::endl;
    // std::cout << "a: " << a.toFloat() << ", b: " << b.toFloat() << std::endl;
    // std::cout << "a++: " << (a++).toFloat() << " " << (a).toFloat() << std::endl;
    // std::cout << "a--: " << (a--).toFloat() << " " << (a).toFloat() << std::endl;
    // std::cout << "++a: " << (++a).toFloat() << " " << (a).toFloat() << std::endl;
    // std::cout << "--a: " << (--a).toFloat() << " " << (a).toFloat() << std::endl;

    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}