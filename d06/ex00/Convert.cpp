#include "Convert.hpp"
#include <iostream>
#include <cmath>

Convert::Convert() {
}

Convert::Convert(Convert const &src) {
	*this = src;
}

Convert::~Convert() {
}

Convert &Convert::operator=(Convert const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

char	Convert::toChar(double val) {
	if (val > std::numeric_limits<char>::max() || val < std::numeric_limits<char>::min() || std::isnan(val) || std::isinf(val))
		throw ImpossibleConversion();
	return static_cast<char>(val);
}
int		Convert::toInt(double val) {
	if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min() || std::isnan(val) || std::isinf(val))
		throw ImpossibleConversion();
	return static_cast<int>(val);
}
float	Convert::toFloat(double val) {
	if (val > std::numeric_limits<float>::max())
		return std::numeric_limits<float>::infinity();
	return static_cast<float>(val);
}

const char* Convert::ImpossibleConversion::what() const throw() {
    return ("impossible");
}
