#include "Attacking.h"
#include <Defending.h>
#include <Taunting.h>

void Attacking::defending(PlayerFSM* a)
{
	std::cout << "Attacking -> Defending" << std::endl;
	a->setCurrent(new Defending());
	delete this;
}

void Attacking::taunting(PlayerFSM* a)
{
	std::cout << "Attacking -> Taunting" << std::endl;
	a->setCurrent(new Taunting());
	delete this;
}


