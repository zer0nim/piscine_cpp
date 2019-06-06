#include "Pony.hpp"

Pony::Pony(std::string name) : _name(name)
{
    std::cout << "Create Pony" << std::endl;
}

Pony::~Pony()
{
    std::cout << "Destroy Pony ! Rwlrwlrwlrwl !" << std::endl;
}


void    Pony::neighing() const {
    std::cout << "Rwlrwlrwlrwl ! I'm " << this->_name << " !" << std::endl;
}
