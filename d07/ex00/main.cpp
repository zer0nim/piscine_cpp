#include "whatever.cpp"
#include <string>
#include <iostream>

class MyInt {
	public:
		MyInt(int val): _val(val) {};
		~MyInt() {};
		int _val;

		// comparison operators
		bool	operator>(MyInt const &rhs) const {
			return _val > rhs._val;
		}
		bool	operator<(MyInt const &rhs) const {
			return _val < rhs._val;
		}
	private:
		MyInt() {};
};

std::ostream    &operator<<(std::ostream &o, MyInt const &myInt) {
	o << myInt._val;
    return o;
}

int main(void) {
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap<int>(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << "max(a, b) = " << max(a, b) << std::endl << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap<std::string>(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;

	MyInt myint1(1024);
	MyInt myint2(42);
	std::cout << "myint1 = " << myint1 << ", myint2 = " << myint2 << std::endl;
	std::cout << "min<MyInt>(myint1, myint2) = " << min<MyInt>(myint1, myint2) << std::endl;
	std::cout << "max<MyInt>(myint1, myint2) = " << max<MyInt>(myint1, myint2) << std::endl;

	return 0;
}