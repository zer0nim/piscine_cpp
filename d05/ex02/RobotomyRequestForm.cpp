#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45) {
	srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45, target) {
	srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	canExecute(executor);
	std::cout << "CRZRZRRrrZRRXRRZrrzrZRrZRRZrrcxxc" << std::endl;

	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomized failure on " << getTarget() << std::endl;
}
