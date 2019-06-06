#include "mutantstack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() {
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const &src) {
	*this = src;
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {
}

template<typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(MutantStack const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

template<typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::begin() {
	return std::begin(std::stack<T, Container>::c);
}

template<typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::end() {
	return std::end(std::stack<T, Container>::c);
}

template<typename T, typename Container>
typename Container::const_iterator	MutantStack<T, Container>::begin() const {
	return std::begin(std::stack<T, Container>::c);
}

template<typename T, typename Container>
typename Container::const_iterator	MutantStack<T, Container>::end() const {
	return std::end(std::stack<T, Container>::c);
}
