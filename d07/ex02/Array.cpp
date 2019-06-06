#ifndef ARRAY_CPP
# define ARRAY_CPP

# include <cstdlib>
# include <exception>

template<typename T>
class Array {
	public:
		Array<T>(): _data(NULL), _size(0) {
		}
		Array<T>(unsigned int n): _data(new T[n]), _size(n){
		};

		Array<T>(Array const &src) {
			*this = src;
		}
		~Array<T>() {
			delete [] _data;
		}

		Array	&operator=(Array const &rhs) {
			if (this != &rhs) {
				_size = rhs.size();
				_data = new T[rhs.size()];
				for (unsigned int i = 0; i < _size; ++i)
					_data[i] = rhs[i];
			}
			return *this;
		}
		T		&operator[] (unsigned int i) const {
			if (i >= _size)
				throw Array<T>::OutOfBoundException();
			return _data[i];
		}
		unsigned int	size() const { return _size; }

		class OutOfBoundException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Out of bound exception !";
				}
		};
	private:
		T				*_data;
		unsigned int	_size;
};

#endif
