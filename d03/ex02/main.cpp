#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    FragTrap    fragTrap1("FR4G-TP");
    FragTrap    fragTrap2("FR4G-TP 2");
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
    std::cout << std::endl;




    ScavTrap    scavTrap1("Scav");
    ScavTrap    scavTrap2("SC4V-TP");
    std::cout << std::endl;

    scavTrap1.rangedAttack("Lilith");
    scavTrap1.meleeAttack("Lilith");
    scavTrap1.takeDamage(50);
    scavTrap1.beRepaired(30);
    std::cout << std::endl;

    for (int i = 0; i < 5; ++i) {
        scavTrap1.challengeNewcomer("Lilith");
    }

    std::cout << std::endl;
    scavTrap2.challengeNewcomer("Lilith");
    std::cout << std::endl;

    ScavTrap    scavTrap1Copy = scavTrap1;
    scavTrap1Copy.challengeNewcomer("Lilith");
    std::cout << std::endl;

    return 0;
}