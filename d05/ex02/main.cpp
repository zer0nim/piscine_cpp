#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat bill("bill", 72);
    ShrubberyCreationForm shrubberyCreation("Hey");
    RobotomyRequestForm robotomyRequest("Hey");
    PresidentialPardonForm presidentialPardon("Hey");

    std::cout << bill << std::endl;

    std::cout << std::endl;
    std::cout << "test: bill try to execute form: \"";
    std::cout << presidentialPardon << "\""<< std::endl;
    bill.executeForm(presidentialPardon);

    std::cout << std::endl;
    std::cout << "test: bill try to sign form: \"";
    std::cout << presidentialPardon << "\""<< std::endl;
    bill.signForm(presidentialPardon);

    std::cout << std::endl;
    std::cout << "test: bill try to execute form: \"";
    std::cout << shrubberyCreation << "\""<< std::endl;
    bill.executeForm(shrubberyCreation);

    std::cout << std::endl;
    bill.signForm(shrubberyCreation);

    std::cout << std::endl;
    std::cout << "test: bill try to execute form: \"";
    std::cout << shrubberyCreation << "\""<< std::endl;
    bill.executeForm(shrubberyCreation);

    std::cout << std::endl;
    std::cout << "test: bill try to sign form: \"";
    std::cout << robotomyRequest << "\""<< std::endl;
    bill.signForm(robotomyRequest);

    std::cout << std::endl;
    std::cout << "test: bill try to execute form: \"";
    std::cout << robotomyRequest << "\""<< std::endl;
    bill.executeForm(robotomyRequest);

    std::cout << std::endl;
    std::cout << "create new burocrate: \"";
    Bureaucrat bob("bob", 1);
    std::cout << bob << "\""<< std::endl;

    std::cout << std::endl;
    std::cout << "test: bob try to execute form: \"";
    std::cout << presidentialPardon << "\""<< std::endl;
    bob.executeForm(presidentialPardon);

    std::cout << std::endl;
    bob.signForm(presidentialPardon);
    std::cout << "test: bob try to execute form: \"";
    std::cout << presidentialPardon << "\""<< std::endl;
    bob.executeForm(presidentialPardon);

    std::cout << std::endl;
    std::cout << "test: bob try to execute form: \"";
    std::cout << robotomyRequest << "\""<< std::endl;
    bob.executeForm(robotomyRequest);

    return 0;
}
