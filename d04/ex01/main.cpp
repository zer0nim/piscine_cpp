#include <iostream>
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int main(void)
{
    Character* zaz = new Character("zaz");

    std::cout << *zaz;

    Enemy* b = new RadScorpion();

    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();

    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);

    zaz->attack(b);
    std::cout << *zaz;
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;

    std::cout << std::endl << "test recoverAP" << std::endl;
    for (size_t i = 0; i < 3; i++)
    {
        zaz->recoverAP();
        std::cout << *zaz;
    }

    std::cout << std::endl << "test attack without amo" << std::endl;
    zaz->equip(NULL);
    zaz->attack(b);

    std::cout << std::endl << "check enemy hp, ap cost, damage" << std::endl;
    Enemy* c = new SuperMutant();
    std::cout << c->getType() << " has " << c->getHP() << " hp " << std::endl;
    zaz->equip(pr);
    std::cout << *zaz;
    std::cout << pr->getName() << " cost " << pr->getAPCost() << " ap and make " << pr->getDamage() << " damages" << std::endl;
    zaz->attack(b);
    std::cout << *zaz;
    std::cout << c->getType() << " has " << c->getHP() << " hp " << std::endl;
    std::cout << std::endl;

    zaz->equip(pf);
    std::cout << *zaz;
    std::cout << pf->getName() << " cost " << pf->getAPCost() << " ap and make " << pf->getDamage() << " damages" << std::endl;
    zaz->attack(b);
    std::cout << *zaz;
    std::cout << c->getType() << " has " << c->getHP() << " hp " << std::endl;


    std::cout << std::endl << "change enemy" << std::endl;
    Enemy* d = new RadScorpion();
    std::cout << d->getType() << " has " << d->getHP() << " hp " << std::endl;
    zaz->attack(d);
    std::cout << *zaz;
    std::cout << d->getType() << " has " << d->getHP() << " hp " << std::endl;
    return 0;
}