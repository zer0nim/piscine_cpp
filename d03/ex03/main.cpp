#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>

int main(void)
{
    FragTrap    frag1("frag1");
    ScavTrap    scav1("scav1");
    NinjaTrap   ninja1("ninja1");
    NinjaTrap   ninja2("ninja2");
    std::cout << std::endl;

    ninja1.ninjaShoebox(frag1);
    ninja1.ninjaShoebox(scav1);
    ninja1.ninjaShoebox(ninja2);
    std::cout << std::endl;

    return 0;
}