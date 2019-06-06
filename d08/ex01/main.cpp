#include "span.hpp"
#include <iostream>
#include <algorithm>

void testAddNb(Span &sp, int nb) {
	try {
		std::cout << "try to add " << nb << ": ";
		sp.addNumber(nb);
		std::cout << "ok" << std::endl;
	}
	catch(const Span::ArrayFullException& e) {
		std::cerr << e.what() << std::endl;
	}
}

void testSpan(Span &sp, bool shorted) {
	try {
		if (shorted)
			std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		else
			std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch(const Span::AtLeastTwoException& e) {
		std::cerr << e.what() << std::endl;
	}
}

struct IncGenerator {
    int current_;
    IncGenerator (int start) : current_(start) {}
    int operator() () { return current_++; }
};

int main(void)
{
	int testVals[] = {5, 3, 17, 9, 11};
	Span sp = Span(5);
	std::cout << "Span sp = Span(5);" << std::endl;

	std::cout << std::endl;
	sp.printValues();
	testSpan(sp, true);
	testSpan(sp, false);

	std::cout << std::endl;
	testAddNb(sp, 42);
	sp.printValues();
	testSpan(sp, true);
	testSpan(sp, false);

	std::cout << std::endl;
	sp.addNumber(5);
	sp.printValues();
	testSpan(sp, true);
	testSpan(sp, false);

	std::cout << std::endl;
	for (int i = 0; i < 6; ++i)
		testAddNb(sp, testVals[i]);
	sp.printValues();
	testSpan(sp, true);
	testSpan(sp, false);
	std::cout << "_____________________Test huge: 0, 1, 2, 3, .... " << std::endl;

	std::vector<int> v(10000000);
	IncGenerator g(0);
	std::generate(v.begin(), v.end(), g);

	Span sp2 = Span(10000000);
	sp2.addRange(v.begin(), v.end());
	testSpan(sp2, true);
	testSpan(sp2, false);

	return 0;
}
