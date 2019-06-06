#include "span.hpp"
# include <algorithm>
# include <iostream>
# include <climits>

Span::Span() {
}

Span::Span(unsigned int n) {
	_data = std::vector<int>(n, 0);
	_it = _data.begin();
}

Span::Span(Span const &src) {
	*this = src;
}

Span::~Span() {
}

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		_data = rhs.getData();
		_it = rhs.getIt();
	}
	return *this;
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (end - begin > _data.end() - _it)
		throw ArrayFullException();

	for (std::vector<int>::iterator it = begin; it != end; it++) {
		*_it = *it;
		_it++;
	}

	std::sort(_data.begin(), _it);
}

void	Span::addNumber(int nb) {
	if (_it == _data.end())
		throw ArrayFullException();

	_data.at(_it - _data.begin()) = nb;
	_it++;

	std::sort(_data.begin(), _it);
}

int		Span::shortestSpan() {
	if (_it - _data.begin() <= 1)
		throw AtLeastTwoException();

	int min = INT_MAX;
	for (std::vector<int>::iterator it = _data.begin() + 1; it != _it; it++) {
		if (min > (*it - *(it - 1)))
			min = *it - *(it - 1);
	}
	return min;
}

int		Span::longestSpan() {
	if (_it - _data.begin() <= 1)
		throw AtLeastTwoException();
	return  *(_it - 1) - *(_data.begin());
}

const char* Span::ArrayFullException::what() const throw() {
	return "Array is full !";
}
const char* Span::AtLeastTwoException::what() const throw() {
	return "Need at least two element to compare !";
}

void		Span::printValues() {
	std::cout << "____________" << std::endl;
	if (_it == _data.begin())
		std::cout << "Empty array";
	for (std::vector<int>::iterator it = _data.begin(); it != _it; ++it) {
		std::cout << " " << *it;
	}
	std::cout << ":" << std::endl;
}

std::vector<int> Span::getData() const { return _data; }
std::vector<int>::iterator Span::getIt() const { return _it; }
