#include "Network.h"

Network::Network(Router* r)
	: router(r)
{}

void Network::addComputer(Computer* c)
{
	router->addDevice(c);
}
