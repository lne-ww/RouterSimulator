#include "Computer.h"
#include <iostream>

Computer::Computer(std::string _address, std::string _name, const Itf& _itf)
	: Device(_address, _name), itf(_itf)
{
}

Computer::Computer(std::string _address, std::string _name, std::string itfName, Device* _devicePtr)
	:Device(_address, _name)
{
	itf = Itf(itfName, _devicePtr);
}

bool Computer::send(Packet p) const
{
	std::cout << "Computer " << getName() << " sent a packet." << std::endl;
	return itf.devicePtr->send(p);
}

bool Computer::receive(Packet p) const
{
	std::cout << "Computer " << getName() << " receive a packet from router." << std::endl;
	std::cout << p;
	return true;
}

Itf Computer::getItf() const
{
	return itf;
}