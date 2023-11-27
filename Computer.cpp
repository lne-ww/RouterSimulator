#include "Computer.h"
#include <iostream>

Computer::Computer()
	: itf("")
{
}

bool Computer::send(Packet p)
{
	std::cout << "Computer "" sent a packet to router";
	return routerPtr->send(p);
}
