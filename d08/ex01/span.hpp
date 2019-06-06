#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span {
	public:
		Span(unsigned int n);
		Span(Span const &src);
		~Span();

		Span &operator=(Span const &rhs);

		void	addNumber( int nb);
		int		shortestSpan();
		int		longestSpan();

		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class ArrayFullException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class AtLeastTwoException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void	printValues();
		std::vector<int> getData() const;
		std::vector<int>::iterator getIt() const;
	private:
		Span();
		std::vector<int> _data;
		std::vector<int>::iterator _it;
};

#endif
