#ifndef TAUNTING_H
#define TAUNTING_H

#include <State.h>

class Taunting : public State
{
public:
	Taunting() {};
	~Taunting() {};
	void idle(PlayerFSM* a);
	void defending(PlayerFSM* a);
	
	void attacking(PlayerFSM* a);
};

#endif
