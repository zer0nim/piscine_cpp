#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>


class Convert {
	public:
		Convert(Convert const &src);
		~Convert();

		Convert &operator=(Convert const &rhs);
		static	char	toChar(double val);
		static	int		toInt(double val);
		static	float	toFloat(double val);

		class ImpossibleConversion : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	private:
		Convert();
};

#endif
