#include "Array.cpp"
#include <iostream>
#include <time.h>
#include <random>

// int main(void) {
// 	srand(time(0));
// 	Array<int> nullArray;
// 	try{
// 		std::cout << "nullArray: " << nullArray[0] << std::endl;
// 	}
// 	catch(const std::exception& e) {
// 		std::cerr << e.what() << '\n';
// 	}


// 	Array<int> test(5);
// 	std::cout << test[0] << std::endl;
	// for (int i = 0; i < test.size(); i++)
	// 	test[i] = rand();
// 	for (int i = 0; i < test.size(); i++)
// 		std::cout << test[i] << std::endl;

// 	std::cout << std::endl;
// 	Array<int> test2 = test;
// 	for (int i = 0; i < test2.size(); i++)
// 		std::cout << test2[i] << std::endl;

// 	return 0;
// }


int main(void) {

    srand(time(0));
    Array<int> test(5);
    std::cout << "Array<int> test(5)" << std::endl;
    std::cout << "Array size: " << test.size() << std::endl;

    try {
		for (unsigned int i = 0; i < test.size(); i++)
			test[i] = rand();
		for (unsigned int i = 0; i < test.size(); i++)
			std::cout << "test[" << i << "]: " << test[i] << std::endl;
		std::cout << std::endl;
        std::cout << "cout << test[42]: " << test[42] << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;

    std::cout << "Array <std::string> b(4)" << std::endl;
    Array <std::string> b(4);
    try {
        b[0] = "Hey";
        b[1] = "What's";
        b[2] = "up";
        b[3] = "?";
        for (unsigned int i = 0; i < b.size(); i++)
			std::cout << "b[" << i << "]: " << b[i] << std::endl;
        std::cout << std::endl;
        std::cout << "b[1]: " << b[1] << std::endl;
        std::cout << "b[4]: " << b[4] << std::endl;
    }
    catch(std::exception & e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;

    Array<double> c(5);
    try {
        std::cout << "Array<double> c(5)" << std::endl;
		for (unsigned int i = 0; i < c.size(); i++) {
            c[i] = (i * 0.1 + 1) * 0.078;
			std::cout << "c[" << i << "]: " << c[i] << std::endl;
        }
        std::cout << std::endl;
        std::cout << "c[1]: " << c[1] << std::endl;
        std::cout << "c[4]: " << c[4] << std::endl;
    }
    catch(std::exception & e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;

    Array<int> nullArray;
    try{
        std::cout << "nullArray: " << nullArray[0] << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
	std::cout << std::endl;

	std::cout << "Array<int> test3(5)" << std::endl;
    Array<int> test3(5);
    for (unsigned int i = 0; i < test3.size(); i++)
        test3[i] = rand();
    for (unsigned int i = 0; i < test3.size(); i++)
        std::cout << test3[i] << std::endl;
	std::cout << std::endl;

    Array<int> test2 = test3;
	test3[0] = 42;
	std::cout << "test3[0] = 42" << std::endl;
	std::cout << "cout << test3[0]: " << test3[0] << std::endl;
	std::cout << "cout << test2[0]: " << test2[0] << std::endl;
}