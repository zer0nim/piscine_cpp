#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("noname"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
    *this = src;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
    if (this != &rhs) {
        this->_grade = rhs.getGrade();
    }
    return *this;
}

void	Bureaucrat::incrementGrade() {
    setGrade(_grade - 1);
}
void    Bureaucrat::decrementGrade() {
    setGrade(_grade + 1);
}

void    Bureaucrat::setGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

int         Bureaucrat::getGrade() const { return _grade; }
std::string Bureaucrat::getName() const { return _name; }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high ! maximum value is 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low ! minimum value is 150");
}

std::ostream    &operator<<(std::ostream &o, Bureaucrat const &i) {
    o << i.getName() << ", bureaucrat grade " << i.getGrade();
    return o;
}