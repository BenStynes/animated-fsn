#include <Jumping.h>
#include <Running.h>
#include <Climbing.h>



void Running::climbing(PlayerFSM* a)
{
	std::cout << "Running -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}



void Running::jumping(PlayerFSM* a)
{
	std::cout << "Running -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
