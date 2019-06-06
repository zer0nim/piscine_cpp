#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
class Bureaucrat;

class Form {
	public:
		Form(std::string name);
		Form(std::string name, int reqSignGrade, int reqExecGrade);
		Form(Form const &src);
		~Form();

		Form &operator=(Form const &rhs);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		std::string	getName() const;
		bool		getSigned() const;
		int			getReqSignGrade() const;
		int			getReqExecGrade() const;

		void		beSigned(Bureaucrat &bureaucrat);
	private:
		Form();

		std::string const	_name;
		bool				_signed;
		int const			_reqSignGrade;
		int const			_reqExecGrade;
};

std::ostream    &operator<<(std::ostream &o, Form const &i);

#endif