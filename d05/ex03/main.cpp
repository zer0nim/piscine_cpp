#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Intern  someRandomIntern;
    AForm*   rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "target1");
    if (rrf)
        std::cout << *rrf << std::endl << std::endl;

    rrf = someRandomIntern.makeForm("robotomy request", "target2");
    if (rrf)
        std::cout << *rrf << std::endl << std::endl;

    rrf = someRandomIntern.makeForm("presidential pardon", "target3");
    if (rrf)
        std::cout << *rrf << std::endl << std::endl;

    rrf = someRandomIntern.makeForm("dsincjdsncihbndsoviu", "target4");
    if (rrf)
        std::cout << *rrf << std::endl;
    return 0;
}
