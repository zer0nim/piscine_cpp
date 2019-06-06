#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>
# include <stack>

template< typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack<T, Container>();
		MutantStack<T, Container>(MutantStack<T, Container> const &src);
		~MutantStack<T, Container>();

		MutantStack<T, Container>	&operator=(MutantStack const &rhs);

		typedef typename Container::iterator iterator;

		typename Container::iterator	begin();
		typename Container::iterator	end();

		typename Container::const_iterator	begin() const;
		typename Container::const_iterator	end() const;
};

#endif