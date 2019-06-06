#include "iter.cpp"
#include <iostream>
#include <string>
#include <cctype>

void	printUpper(char const &c) {
	std::cout << std::string(1, toupper(c));
}

void	oddEven(int const &nb) {
	std::cout << nb << ": " << ((nb % 2) ? "odd" : "even") << std::endl;
}

class Pos {
	public:
		Pos(): x(0), y(0) {};
		Pos(int x, int y): x(x), y(y) {};
		Pos(Pos const &src) {
			*this = src;
		}
		Pos &operator=(Pos const &rhs) {
			if (this != &rhs)
				this->x = rhs.x;
				this->y = rhs.y;
			return *this;
		}
		~Pos() {};
		int x;
		int y;
};

std::ostream    &operator<<(std::ostream &o, Pos const &pos) {
	o << "{x:" << pos.x << " y:" << pos.y << "}";
    return o;
}

template <typename T>
void show(T const &val) {
	std::cout << "val: " << val << std::endl;
}

int main(void) {
	// char * ______________
	char	test[] = "HeY WhaT'S UP !";
	iter<char, int>(test, std::strlen(test), printUpper);
	std::cout << std::endl << std::endl;

	// array of int ______________
	int nbArr[] = {42, 5, 12, -3, 56, 32, 52};
	iter<int, int>(nbArr, 7, oddEven);
	std::cout << std::endl;

	// array of object ______________
	Pos posArr[2];
	posArr[0] = Pos(42, 33);
	posArr[1] = Pos(-26, 69);
	iter<Pos, int>(posArr, 2, show);
	return 0;
}
