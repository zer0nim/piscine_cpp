#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Form;

class Bureaucrat {
	public:
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &rhs);

		int         getGrade() const;
		std::string getName() const;

		void	incrementGrade();
		void    decrementGrade();

		void	signForm(Form &form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
	private:
		Bureaucrat();
		void    setGrade(int grade);

		std::string const   _name;
		int                 _grade;
};

std::ostream    &operator<<(std::ostream &o, Bureaucrat const &i);

#endif