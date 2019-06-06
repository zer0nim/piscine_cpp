#include "ZombieEvent.hpp"
#include "Zombie.hpp"

int main(void) {
    Zombie  *zombs[2];
    ZombieEvent ze;

    zombs[0] = ze.newZombie("bill");
    zombs[0]->announce();

    ze.setZombieType("type2");
    zombs[1] = ze.newZombie("chloe");
    zombs[1]->announce();

    ze.randomChump();

    for (int i = 0; i < 2; i++)
        delete zombs[i];
    return 0;
}
