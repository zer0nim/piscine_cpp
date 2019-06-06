#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
};

Intern::~Intern() {
};

AForm	*Intern::makeForm(std::string formName, std::string target) {
	AForm	*form;

	if (formName.compare("shrubbery creation") == 0) {
		form = new ShrubberyCreationForm(target);
	} else if (formName.compare("robotomy request") == 0) {
		form = new RobotomyRequestForm(target);
	} else if (formName.compare("presidential pardon") == 0) {
		form = new PresidentialPardonForm(target);
	} else {
		std::cout << "formName is not recognized, available formName are:" << std::endl;
		std::cout << "\t\"shrubbery creation\", \"robotomy request\", \"presidential pardon\"" << std::endl;
		return NULL;
	}

	std::cout << "Intern creates " << formName << std::endl;
	return form;
}
