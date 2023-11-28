#include "Router.h"
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

bool Router::send(Packet p)
{
	std::cout << "router " << this->getName() << " received a packet" << std::endl;
	for(std::vector<Route>::iterator it = routingTable.begin(); it != routingTable.end(); it++)
	{
		if(it->end == p.end)
		{
			it->devicePtr->send(p);
			return 1;
		}		
	}
	std::cout << "packet loss" << std::endl;
	return 0;
}