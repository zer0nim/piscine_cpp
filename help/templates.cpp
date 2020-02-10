#include <iostream>
#include <iomanip>
#include <string>

/* ------------------------ simple function template ------------------------ */
template<typename T>
T const	&myMax(T const &lhs, T const &rhs) {
	return (lhs > rhs) ? lhs : rhs;
}

// usage example
void example1() {
	std::cout << "\n------------------------ simple function template ------------------------" << std::endl;
	std::cout << "myMax<int>(21, 42): " << myMax<int>(21, 42) << std::endl;
}


/* -------------------------- simple class template ------------------------- */
template<typename T>
class MyVec2 {
	public:
		MyVec2<T>(T a, T b)
		: _a(a), _b(b) {};

		virtual ~MyVec2<T>() {};

		T	getMax() {
			return myMax<T>(_a, _b);
		}

	private:
		T	_a, _b;
};

// to define a function member outside the declaration of the class template,
// we must always precede that definition with the template <...> prefix:
// example:

// template <class T>
// T	MyVec2<T>::getMax() {
// 	return myMax<T>(_a, _b);
// }

// usage example
void example2() {
	std::cout << "\n-------------------------- simple class template -------------------------" << std::endl;
	MyVec2<int>	pairInt(21, 42);
	std::cout << "MyVec2<int> pairInt(21, 42);" << std::endl;
	std::cout << "pairInt.max(): " << pairInt.getMax() << std::endl;

	MyVec2<std::string>	pairStr("aa", "bb");
	std::cout << "\nMyVec2<std::string> pairStr(\"aa\", \"bb\");" << std::endl;
	std::cout << "pairStr.max(): " << pairStr.getMax() << std::endl;
}

/* ------------------ default type and operator overloading ----------------- */
template<typename T = float>
class Vertex3 {
	public:
		Vertex3<T>(T x, T y, T z)
		: _x(x), _y(y), _z(z) {}

		virtual ~Vertex3<T>() {}

		T	getX() const { return _x; }
		T	getY() const { return _y; }
		T	getZ() const { return _z; }

	private:
		T	_x, _y, _z;
};

template<typename T>
std::ostream & operator << (std::ostream &out, Vertex3<T> const &aV3) {
	out << typeid(T).name() << "Vec3" << std::fixed << std::setprecision(1);
	out << "{" << aV3.getX() << ", " << aV3.getY() << ", " << aV3.getZ()
		<< "}" << std::endl;
	return out;
}

// usage example
void example3() {
	std::cout << "\n------------------ default type and operator overloading -----------------" << std::endl;
	std::cout << "[default T] Vertex3<>(10, 11, 12): " << Vertex3<>(10, 11, 12) << std::endl;
	std::cout << "[specified T] Vertex3<int>(1, 2, 3): " << Vertex3<int>(1, 2, 3) << std::endl;
}

/* ------------------------- template specialization ------------------------ */
// generic class template
template<typename T, typename U>
class MyPair {
	public:
		MyPair<T, U>(T a, U b)
		: _a(a), _b(b) {
			std::cout << "constructor: generic" << std::endl;
		}

		virtual ~MyPair<T, U>() {}

		T	getA() const { return _a; }
		U	getB() const { return _b; }

	private:
		T	_a;
		U	_b;
};

template<typename T, typename U>
std::ostream & operator << (std::ostream &out, MyPair<T, U> const &aPair) {
	out << "MyPair<" << typeid(T).name() << ", " << typeid(U).name() << ">";
	out << std::fixed << std::setprecision(1) << std::boolalpha;
	out << "{" << aPair.getA() << ", " << aPair.getB() << "}";
	return out;
}

// partial specialization: <T, bool>
template<typename T>
class MyPair<T, bool> {
	public:
		MyPair<T, bool>(T a, bool b)
		: _a(a), _b(b) {
			std::cout << "constructor: <T, bool> partial specialization" << std::endl;
		}

		virtual ~MyPair<T, bool>() {}

		T		getA() const { return _a; }
		bool	getB() const { return _b; }

	private:
		T		_a;
		bool	_b;
};

// complete specialization: <bool, bool>
template<>  // no types variables needed
class MyPair<bool, bool> {
	public:
		MyPair<bool, bool>(bool a, bool b) {
			_aB = 0;
			_aB |= static_cast<int>(a);
			_aB |= static_cast<int>(b) << 1;
			std::cout << "constructor: <bool, bool> complete specialization" << std::endl;
		}

		virtual ~MyPair<bool, bool>() {}

		bool	getA() const { return _aB & 0x01; }
		bool	getB() const { return _aB & 0x02; }

	private:
		uint8_t	_aB;
};

// complete specialization: <bool, bool>
std::ostream & operator << (std::ostream &out, MyPair<bool, bool> const &aPair) {
	out << "/* bool, bool specialization */\t";
	out << "MyPair<b, b>";
	out << std::boolalpha;
	out << "{" << aPair.getA() << ", " << aPair.getB() << "}";
	return out;
}

void example4() {
	std::cout << "\n------------------------- template specialization ------------------------" << std::endl;
	std::cout << "MyPair<char, int> pair1('u', 12);" << std::endl;
	MyPair<char, int>	pair1('u', 12);
	std::cout << "cout: \"" << pair1 << '"' << std::endl;

	std::cout << "\nMyPair<int, bool> pair2(42, true);" << std::endl;
	MyPair<int, bool>	pair2(42, true);
	std::cout << "cout: \"" << pair2 << '"' << std::endl;

	std::cout << "\nMyPair<bool, bool> pair3(false, true);" << std::endl;
	MyPair<bool, bool>	pair3(false, true);
	std::cout << "cout: \"" << pair3 << '"' << std::endl;
}


/* ---------------------------------- main ---------------------------------- */
int	main() {
	example1();
	example2();
	example3();
	example4();
	return EXIT_SUCCESS;
}
