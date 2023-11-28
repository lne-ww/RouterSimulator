#pragma once
#include "Router.h"
#include "Computer.h"
class Network
{
public:
	Network(Router* r);
	void addComputer(Computer* c) const;
	void connect(Network other) const;
	void info() const;

private:
	Router* router;

};

