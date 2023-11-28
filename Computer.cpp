#include "Computer.h"
#include <iostream>

Computer::Computer(std::string _itf)
	: itf(_itf)
{
}

bool Computer::send(Packet p)
{
	if(p.end == this->getAddress())
	std::cout << "Computer " << this->getName() <<" sent a packet to router: " << p.payload;
	return routerPtr->send(p);
}

bool Computer::receive(Packet p)
{
	std::cout << "Computer " << this->getName() <<" receive a packet from router: " << p.payload;
	return 1;
}
