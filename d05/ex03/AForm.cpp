#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("noname"), _signed(false), _reqSignGrade(2), _reqExecGrade(5) {
}

AForm::AForm(std::string name) : _name(name), _signed(false), _reqSignGrade(2), _reqExecGrade(5) {
}

AForm::AForm(std::string name, int reqSignGrade, int reqExecGrade)
: _name(name), _signed(false), _reqSignGrade(reqSignGrade), _reqExecGrade(reqExecGrade) {
	if (_reqSignGrade < 1 || _reqExecGrade < 1)
        throw GradeTooHighException();
    else if (_reqSignGrade > 150 || _reqExecGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(std::string name, int reqSignGrade, int reqExecGrade, std::string target)
: _name(name), _target(target), _signed(false), _reqSignGrade(reqSignGrade), _reqExecGrade(reqExecGrade) {
	if (_reqSignGrade < 1 || _reqExecGrade < 1)
        throw GradeTooHighException();
    else if (_reqSignGrade > 150 || _reqExecGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const &src) : _reqSignGrade(src.getReqSignGrade()), _reqExecGrade(src.getReqExecGrade()) {
	*this = src;
}

AForm::~AForm() {
}

AForm &AForm::operator=(AForm const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

std::string	AForm::getName() const { return _name; }
std::string	AForm::getTarget() const { return _target; }
bool		AForm::getSigned() const { return _signed; }
int			AForm::getReqSignGrade() const { return _reqSignGrade; }
int			AForm::getReqExecGrade() const { return _reqExecGrade; }

const char* AForm::GradeTooHighException::what() const throw() {
    return ("AForm: Grade is too high !");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("AForm: Grade is too low !");
}

const char* AForm::FormNotSignedException::what() const throw() {
    return ("AForm: Form is not signed !");
}

void	AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > getReqSignGrade())
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::canExecute(Bureaucrat const &bureaucrat) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (bureaucrat.getGrade() > getReqExecGrade())
		throw GradeTooLowException();
}

std::ostream    &operator<<(std::ostream &o, AForm const &i) {
    o << i.getName() << "=> signed: " << (i.getSigned() ? "false" : "true") \
	<< ", requireSignGrade:" << i.getReqSignGrade() \
	<< ", requireExecGrade:" << i.getReqExecGrade();
    return o;
}
