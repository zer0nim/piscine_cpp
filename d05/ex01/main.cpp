#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::cout << std::endl;
    std::cout << "test 1: bob.signForm(form)" << std::endl;
    Bureaucrat bob = Bureaucrat("bob", 43);
    Form form("Laisser passer A38", 42, 80);
    std::cout << "- " << bob << std::endl;
    std::cout << "- " << form << std::endl;
    bob.signForm(form);
    std::cout << "- " << form << std::endl;

    std::cout << std::endl;
    bob.incrementGrade();

    std::cout << "test 2: bob.signForm(form)" << std::endl;
    std::cout << "- " << bob << std::endl;
    std::cout << "- " << form << std::endl;
    bob.signForm(form);
    std::cout << "- " << form << std::endl;



    std::cout << std::endl;
    try
    {
        std::cout << "test 3: form creation with ReqSignGrade set to -5" << std::endl;
        Form("Laisser passer b47", -5, 80);
        std::cout << "when well ! : " << bob << std::endl;
    }
    catch(const Form::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try
    {
        std::cout << "test 4: form creation with ReqSignGrade set to 152" << std::endl;
        Form("Laisser passer b47", 152, 80);
        std::cout << "when well ! : " << bob << std::endl;
    }
    catch(const Form::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try
    {
        std::cout << "test 4: form creation with ReqExecGrade set to -5" << std::endl;
        Form("Laisser passer b47", 80, -5);
        std::cout << "when well ! : " << bob << std::endl;
    }
    catch(const Form::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try
    {
        std::cout << "test 5: form creation with ReqExecGrade set to 152" << std::endl;
        Form("Laisser passer b47", 80, 152);
        std::cout << "when well ! : " << bob << std::endl;
    }
    catch(const Form::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
