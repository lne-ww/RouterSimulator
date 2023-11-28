#include "Computer.h"
#include <iostream>

Computer::Computer(std::string _itf, Router* _routerPtr)
	: itf(_itf), routerPtr(_routerPtr)
{
}

bool Computer::send(Packet p) const
{
	std::cout << "Computer " << getName() << " sent a packet." << std::endl;
	return routerPtr->send(p);
}

bool Computer::receive(Packet p) const
{
	std::cout << "Computer " << getName() << " receive a packet from router." << std::endl;
	std::cout << p;
	return true;
}
