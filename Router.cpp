#include "Router.h"
#include "Computer.h"
#include <iostream>

/*
maybe useful
std::string extractRouterAddress(std::string address)
{
	int cursor = 0;
	for(int dotCounter = 0; dotCounter != 2; cursor++)
	{
		if(address[cursor] == '.')dotCounter++;
	}
	return address.substr(0, cursor);
}
*/

Route::Route(std::string _end, std::string _nextHop, std::string _itfName, Device* ptr)
	: end(_end), nextHop(_nextHop), itfName(_itfName), devicePtr(ptr)
{
}

Router::Router()
	: routingTable()
{
}

bool Router::send(Packet p) const
{
	std::cout << "router " << this->getName() << " received a packet" << std::endl;
	for(std::vector<Route>::const_iterator it = routingTable.begin(); it != routingTable.end(); it++)
	{
		if(it->end == p.end)
		{
			Router* ptr = dynamic_cast<Router*>(it->devicePtr);
			if (ptr != nullptr) // if end is a router
			{
				std::cout << "Router " + getName() + " sent a packet to Router " + ptr->getName() << std::endl;
				return ptr->send(p);
			}
			else // sent to a computer
			{
				return it->devicePtr->receive(p);
			}
		}		
	}
	std::cout << "Packet (sent from Router " << getName() << ") lost. " << std::endl;
	return false;
}

bool Router::receive(Packet p) const
{
	send(p);
	return true;
}

void Router::addDevice(Device* ptr)
{
	/*Route newRoute(ptr->getAddress, )
	routingTable.push_back()*/
}
