#include "Human.hpp"

int main(void)
{
    Human h = Human();
    h.action("meleeAttack", "Zombie");
    h.action("rangedAttack", "Zombie");
    h.action("intimidatingShout", "Zombie");
    h.action("Hug", "Zombie");
    return 0;
}
