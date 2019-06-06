#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <exception>

class NotFindException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "not finded !";
		}
};

template<typename T>
typename T::iterator	easyfind(T intCont, int val) {
	typename T::iterator it;
	it = std::find(intCont.begin(), intCont.end(), val);

	if (it == intCont.end())
		throw NotFindException();
	return it;
}

#endif
