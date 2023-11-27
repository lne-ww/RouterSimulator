#pragma once
#include "Router.h"
#include "Computer.h"
class Network
{
public:
	Network(Router* r);
	void addComputer(Computer* c);

private:
	Router* router;

};

