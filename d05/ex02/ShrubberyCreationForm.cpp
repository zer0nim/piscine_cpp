#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137, target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs)
		;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	canExecute(executor);
	std::cout << "ShrubberyCreationForm" << std::endl;


    std::ofstream   ofs;
    ofs.open(this->getTarget().c_str(), std::ofstream::out);

    if (!ofs)
    {
        std::cerr << "Error opening file !" << std::endl;
        return ;
    }
	ofs << "     ccee88oo" << std::endl;
	ofs << "  C8O8O8Q8PoOb o8oo" << std::endl;
	ofs << " dOB69QO8PdUOpugoO9bD" << std::endl;
	ofs << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
	ofs << "    6OuU  /p u gcoUodpP" << std::endl;
	ofs << "      \\\\//  /douUP" << std::endl;
	ofs << "        \\\\////" << std::endl;
	ofs << "         |||/\\" << std::endl;
	ofs << "         |||\\/" << std::endl;
	ofs << "         |||||" << std::endl;
	ofs << "   .....//||||\\...." << std::endl;
    ofs.close();
}
