#ifndef RUNNING_H
#define RUNNING_H

#include <State.h>

class Running : public State
{
public:
	Running() {};
	~Running() {};
	void climbing(PlayerFSM* a);
	
	void jumping(PlayerFSM* a);
};
#endif
