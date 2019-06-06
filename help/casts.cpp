#include <iostream>
#include <exception>

class Parent					{ public: virtual ~Parent(){} };
class Child1: public Parent		{};
class Child2: public Parent		{};

class Unrelated					{};

// ------------

class A {};
class B {};

class C {
	public:
					C(A const _) { return; }
		explicit	C(B const _) { return; }  // explicit block implicit conversion
};

void	f(C const &_) { return; }

// ------------

int main(int argc, char const *argv[])
{
	// Static_cast __________________________
	{
		Child1	a;
		Parent	*b = &a;

		Child2	*c = static_cast<Child2 *>(b);

		// won't compile !
		// Unrelated	*d = static_cast<Unrelated *>(b);
	}

	// Dynamic_cast __________________________
	{
		Child1	a;
		Parent	*b = &a;

		Child1	*c = dynamic_cast<Child1 *>(b);
		Child1	&d = dynamic_cast<Child1 &>(*b);

		// if the cast is not possible :
		{
			// this will return NULL if we use pointer
			Child2	*e = dynamic_cast<Child2 *>(e);

			// or throw std::bad_cast exeption if we use reference
			try
			{
				Child2	&f = dynamic_cast<Child2 &>(*b);
			}
			catch(const std::bad_cast& e)
			{
			}
		}
	}

	// Reinterpret_cast __________________________
	{
		Child1	a;
		Parent	*b = &a;

		Child1	*c = reinterpret_cast<Child1 *>(b);

		// accept everything
		// this will never return error or null
		Child2		*d = reinterpret_cast<Child2 *>(b);
		Unrelated	*e = reinterpret_cast<Unrelated *>(b);
		Unrelated	&f = reinterpret_cast<Unrelated &>(*b);
	}

	// Const_cast __________________________
	{
		int	a = 42;

		int	const	*b = &a;

		// won't compile !
		// int			*c = b;

		int			*d = const_cast<int *>(b);
	}

	// Redefine implicit cast __________________________
	{
		class Foo {
			public:
				Foo(float const v) : _v(v) { }
				float	getV() { return _v; }
				operator float() { return _v; }
				operator int() { return static_cast<int>(_v); }
			private:
				float _v;
		};

		Foo a(42.280);
		float b = a;
		int c = a;

		std::cout << a.getV() << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}

	// Redefine implicit cast __________________________
	{
		f( A() );

		// Blocked because of the explicit keyword
		// f( B() );
	}

	return 0;
}


// +------------------+-------+--------+--------+----------+------------+
// // |       Cast       | Conv. | Reint. | Upcast | Downcast | Type qual. |
// // +------------------+-------+--------+--------+----------+------------+
// // | Implicit         | Yes   |        | Yes    |          |            |
// // | static_cast      | Yes   |        | Yes    | Yes      |            |
// // | dynamic_cast     |       |        | Yes    | Yes      |            |
// // | const_cast       |       |        |        |          | Yes        |
// // | reinterpret_cast |       | Yes    | Yes    | Yes      |            |
// // | ---------------- | ----- | ------ | ------ | -------- | ---------- |
// // | Legacy C cast    | Yes   | Yes    | Yes    | Yes      | Yes        |
// // +------------------+-------+--------+--------+----------+------------+
//
// // +------------------+----------------+-----------------+---------------+
// // |       Cast       | Semantic check | Reliable at run | Tested at run |
// // +------------------+----------------+-----------------+---------------+
// // | Implicit         | Yes            | Yes             |               |
// // | static_cast      | Yes            |                 |               |
// // | dynamic_cast     | Yes            | Yes             | Yes           |
// // | const_cast       |                |                 |               |
// // | reinterpret_cast |                |                 |               |
// // | ---------------- | -------------- | --------------- | ------------- |
// // | Legacy C cast    |                |                 |               |
// // +------------------+----------------+-----------------+---------------+
