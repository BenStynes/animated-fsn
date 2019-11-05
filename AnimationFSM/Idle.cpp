#include <Idle.h>
#include <Jumping.h>
#include <Climbing.h>
#include<Attacking.h>
#include<Defending.h>
#include<Taunting.h>
#include<Running.h>
#include <string>

void Idle::handleInput() {}
void Idle::update() {}

void Idle::jumping(PlayerFSM* a)
{
	std::cout << "Idle -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
void Idle::climbing(PlayerFSM* a)
{
	std::cout << "Idle -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}

void Idle::attacking(PlayerFSM* a)
{
	std::cout << "Idle -> Attacking" << std::endl;
	a->setCurrent(new Attacking());
	delete this;
}

void Idle::defending(PlayerFSM* a)
{
	std::cout << "Idle -> Defending" << std::endl;
	a->setCurrent(new Defending());
	delete this;
}

void Idle::taunting(PlayerFSM* a)
{
	std::cout << "Idle -> Taunting" << std::endl;
	a->setCurrent(new Taunting());
	delete this;
}

void Idle::running(PlayerFSM* a)
{
	std::cout << "Idle -> Running" << std::endl;
	a->setCurrent(new Running());
	delete this;
}
