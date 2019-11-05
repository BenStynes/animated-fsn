#include "Defending.h"
#include <Attacking.h>
#include <Taunting.h>




void Defending::taunting(PlayerFSM* a)
{
	std::cout << "Defending -> Taunting" << std::endl;
	a->setCurrent(new Taunting());
	delete this;
}

void Defending::attacking(PlayerFSM* a)
{
	std::cout << "Defending -> Attacking" << std::endl;
	a->setCurrent(new Attacking());
	delete this;
}
