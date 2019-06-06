#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
class Bureaucrat;

class AForm {
	public:
		AForm(std::string name);
		AForm(std::string name, int reqSignGrade, int reqExecGrade);
		AForm(std::string name, int reqSignGrade, int reqExecGrade, std::string target);
		AForm(AForm const &src);
		~AForm();

		AForm &operator=(AForm const &rhs);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		std::string		getName() const;
		std::string		getTarget() const;
		bool			getSigned() const;
		int				getReqSignGrade() const;
		int				getReqExecGrade() const;

		void			setTarget(std::string target);

		void			beSigned(Bureaucrat &bureaucrat);
		void			canExecute(Bureaucrat const &executor) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
	protected:
		AForm();
	private:
		std::string const	_name;
		std::string			_target;
		bool				_signed;
		int const			_reqSignGrade;
		int const			_reqExecGrade;
};

std::ostream    &operator<<(std::ostream &o, AForm const &i);

#endif