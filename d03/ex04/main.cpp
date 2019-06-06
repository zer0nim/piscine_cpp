#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int main(void)
{
    SuperTrap   super1("super1");
    super1.rangedAttack("Handsome Jack");
    super1.meleeAttack("Handsome Jack");
    std::cout << std::endl;

    super1.vaulthunter_dot_exe("Handsome Jack");
    std::cout << std::endl;

    FragTrap   frag1("frag1");
    super1.ninjaShoebox(frag1);
    std::cout << std::endl;

    std::cout << "HitPoints: " << super1.getHitPoints() << std::endl;
    std::cout << "MaxHitPoints: " << super1.getMaxHitPoints() << std::endl;
    std::cout << "EnergyPoints: " << super1.getEnergyPoints() << std::endl;
    std::cout << "MaxEnergyPoints: " << super1.getMaxEnergyPoints() << std::endl;
    std::cout << "MeleeAttackDamage: " << super1.getMeleeAttackDamage() << std::endl;
    std::cout << "RangedAttackDamage: " << super1.getRangedAttackDamage() << std::endl;
    std::cout << "ArmorDamageReduction: " << super1.getArmorDamageReduction() << std::endl;
    std::cout << std::endl;

    return 0;
}