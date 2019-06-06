#include <iostream>
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

int main(void)
{
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;

    ISquad* vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    delete vlc;

    std::cout << std::endl << std::endl << "My test:" << std::endl << std::endl;

    ISpaceMarine* billy = new TacticalMarine;
    ISpaceMarine* maelis = new AssaultTerminator;

    ISquad* vlc2 = new Squad;
    std::cout << "should return NULL " << vlc2->getUnit(0) << std::endl;
    std::cout << "should return 0 " << vlc2->getCount() << std::endl;
    vlc2->push(billy);
    vlc2->push(maelis);
    std::cout << "should return billy adress " << vlc2->getUnit(0) << std::endl;
    std::cout << "should return NULL " << vlc2->getUnit(42) << std::endl;
    std::cout << "should return 2 " << vlc2->getCount() << std::endl;

    ISpaceMarine* boby = jim->clone();
    boby->battleCry();
    delete boby;
    maelis->battleCry();

    delete vlc2;
    return 0;
}
