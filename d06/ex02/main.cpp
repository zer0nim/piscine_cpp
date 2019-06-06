#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void) {
	int randNb = rand() % 3;
	if (randNb == 0) {
		std::cout << "A generated !" << std::endl;
		return new A();
	}
	else if (randNb == 1) {
		std::cout << "B generated !" << std::endl;
		return new B();
	}
	std::cout << "C generated !" << std::endl;
	return new C();
}

void identify_from_pointer(Base *p) {
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch(const std::bad_cast& e) {
	}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	} catch(const std::bad_cast& e) {
	}

	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	} catch(const std::bad_cast& e) {
	}
}

int main(void)
{
	srand(time(0));

	Base	*randClass = generate();

	identify_from_pointer(randClass);
	identify_from_reference(*randClass);
	delete randClass;

	return 0;
}



// Wrap these three functions in a program that prooves that everything works as intended. Including <typeinfo> is forbidden.