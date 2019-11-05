#include <Taunting.h>
#include <Defending.h>
#include <Attacking.h>
#include <Idle.h>

void Taunting::idle(PlayerFSM* a)
{
	std::cout << "Taunting -> idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Taunting::defending(PlayerFSM* a)
{
	std::cout << "Taunting -> Defending" << std::endl;
	a->setCurrent(new Defending());
	delete this;
}



void Taunting::attacking(PlayerFSM* a)
{
	std::cout << "Taunting -> Attacking" << std::endl;
	a->setCurrent(new Attacking());
	delete this;
}
