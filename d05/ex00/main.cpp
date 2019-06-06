#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
    try {
        std::cout << "test Bureaucrat(\"bob\")" << std::endl;
        Bureaucrat bob = Bureaucrat("bob");
        std::cout << "when well ! : " << bob << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        std::cout << "test Bureaucrat(\"bob\", 0)" << std::endl;
        Bureaucrat bob = Bureaucrat("bob", 0);
        std::cout << "when well ! : " << bob << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        std::cout << "test Bureaucrat(\"bob\", 151)" << std::endl;
        Bureaucrat bob = Bureaucrat("bob", 151);
        std::cout << "when well ! : " << bob << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        std::cout << "test increment from 43" << std::endl;
        Bureaucrat bob = Bureaucrat("bob", 43);
        bob.incrementGrade();
        std::cout << "when well ! : " << bob << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        std::cout << "test increment from 1" << std::endl;
        Bureaucrat bob = Bureaucrat("bob", 1);
        bob.incrementGrade();
        std::cout << "when well ! : " << bob << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        std::cout << "test decrement from 150" << std::endl;
        Bureaucrat bob = Bureaucrat("bob", 150);
        bob.decrementGrade();
        std::cout << "when well ! : " << bob << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat    employee("Annoying employee", 150);
    std::cout << employee << std::endl;

    Bureaucrat    copy(employee);
    std::cout << copy << std::endl;
    Bureaucrat    assign = employee;
    std::cout << assign << std::endl;

    return 0;
}
