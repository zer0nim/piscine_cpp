#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    FragTrap    fragTrap1("ClapTrap");
    FragTrap    fragTrap2("FR4G-TP");
    std::cout << std::endl;

    fragTrap1.rangedAttack("Handsome Jack");
    fragTrap1.meleeAttack("Handsome Jack");
    fragTrap1.takeDamage(50);
    fragTrap1.beRepaired(30);
    std::cout << std::endl;

    for (int i = 0; i < 5; ++i) {
        fragTrap1.vaulthunter_dot_exe("Handsome Jack");
    }

    std::cout << std::endl;
    fragTrap2.vaulthunter_dot_exe("Handsome Jack");
    std::cout << std::endl;

    FragTrap    fragTrap1Copy = fragTrap1;
    fragTrap1Copy.vaulthunter_dot_exe("Handsome Jack");
    std::cout << std::endl;

    return 0;
}