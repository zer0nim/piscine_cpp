#include "Pony.hpp"

void    ponyOnTheStack() {
    Pony    pony("Pinkie pie");

    pony.neighing();
}

void    ponyOnTheHeap() {
    Pony    *pony = new Pony("AppleJack");

    pony->neighing();
    delete pony;
}

int     main(void)
{
    ponyOnTheStack();
    ponyOnTheHeap();
    return 0;
}
