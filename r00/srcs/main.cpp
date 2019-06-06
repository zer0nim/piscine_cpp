#include "GameManager.hpp"
#include <ctime>
#include <cstdlib>

int main(void)
{
	srand(time(NULL));
    GameManager gm;

	gm.exec();
    return 0;
}
