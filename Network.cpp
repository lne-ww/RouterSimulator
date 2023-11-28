#include "Network.h"
#include <iostream>

Network::Network(Router* r)
	: router(r)
{}

void Network::addComputer(Computer* c) const
{
	router->addDevice(c);
}

void Network::connect(Network other) const
{
	router->addDevice(other.router);
}

void Network::info() const
{
	// print a list of devices
	std::cout << "Router of this network: " << router->getName() << " at " << router->getAddress() << std::endl;
	std::cout << "Computer(s) in this network: " << std::endl;
	// 5 itfs at most
	Itf* itfPtr = router->getItfs();
	int numberOfDevices = 0;

	for (int i = 0; i < 5; ++i)
	{
		Itf* currentItf = itfPtr + i;
		if (currentItf->devicePtr != nullptr)
		{
			++numberOfDevices;
			std::cout << currentItf->devicePtr->getName() << std::endl;
		}
	}
	if (numberOfDevices == 0)
		std::cout << "No computers in this network now." << std::endl;
	else
		std::cout << numberOfDevices << "computer(s) in total." << std::endl;
}
