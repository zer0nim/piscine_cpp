#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
	int intArrC[] = {52, -9, 33, 6};

	// with stl vector _______________________
	std::cout << "With vector _______________________" << std::endl;
	std::vector<int> intArrV(intArrC, intArrC + 4);
	try {
		std::cout << "Value 33: ";
		easyfind< std::vector<int> >(intArrV, 33);
		std::cout << "finded !" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "Value 42: ";
		easyfind< std::vector<int> >(intArrV, 42);
		std::cout << "finded !" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	// with stl list _______________________
	std::cout << "With list _______________________" << std::endl;
	std::list<int> intArrL(intArrC, intArrC + 4);
	try {
		std::cout << "Value 33: ";
		easyfind< std::list<int> >(intArrL, 33);
		std::cout << "finded !" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "Value 42: ";
		easyfind< std::list<int> >(intArrL, 42);
		std::cout << "finded !" << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
