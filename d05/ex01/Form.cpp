#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("noname"), _signed(false), _reqSignGrade(42), _reqExecGrade(42) {
}

Form::Form(std::string name) : _name(name), _signed(false), _reqSignGrade(42), _reqExecGrade(42) {
}

Form::Form(std::string name, int reqSignGrade, int reqExecGrade)
: _name(name), _signed(false), _reqSignGrade(reqSignGrade), _reqExecGrade(reqExecGrade) {
	if (_reqSignGrade < 1 || _reqExecGrade < 1)
        throw GradeTooHighException();
    else if (_reqSignGrade > 150 || _reqExecGrade > 150)
        throw GradeTooLowException();
}


Form::Form(Form const &src) : _reqSignGrade(src.getReqSignGrade()), _reqExecGrade(src.getReqExecGrade()) {
	*this = src;
}

Form::~Form() {
}

Form &Form::operator=(Form const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

std::string	Form::getName() const { return _name; }
bool		Form::getSigned() const { return _signed; }
int			Form::getReqSignGrade() const { return _reqSignGrade; }
int			Form::getReqExecGrade() const { return _reqExecGrade; }

const char* Form::GradeTooHighException::what() const throw() {
    return ("Form: Grade is too high ! maximum value is 1");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Form: Grade is too low ! maximum value is 150");
}

void	Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > getReqSignGrade())
		throw GradeTooLowException();
	_signed = true;
}

std::ostream    &operator<<(std::ostream &o, Form const &i) {
    o << i.getName() << " is " << (i.getSigned() ? " " : "not ") << "signed" \
	<< ", require sign grade is " << i.getReqSignGrade() \
	<< ", require exec grade is " << i.getReqExecGrade();
    return o;
}
