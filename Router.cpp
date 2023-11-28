#include "Router.h"
#include "Computer.h"
#include <iostream>
#include <iomanip>

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


Route::Route(std::string _end, std::string _nextHop, const Itf& itf)
	: end(_end), nextHop(_nextHop), itf(itf)
{
}

Router::Router(std::string _address, std::string _name)
	: Device(_address, _name), routingTable(), itfs()
{
	for(int i = 0; i < 5; i++)
	{
		itfs[i].name = "interface" + std::to_string(i);
	}
	// ... name for itfs

}


bool Router::send(Packet p) const
{
	std::cout << "router " << this->getName() << " received a packet" << std::endl;
	for(std::vector<Route>::const_iterator it = routingTable.begin(); it != routingTable.end(); it++)
	{
		if(it->end == p.end)
		{
			Router* ptr = dynamic_cast<Router*>(it->itf.devicePtr);
			if (ptr != nullptr) // if end is a router
			{
				std::cout << "Router " + getName() + " sent a packet to Router " + ptr->getName() << std::endl;
				return ptr->send(p);
			}
			else // sent to a computer
			{
				return it->itf.devicePtr->receive(p);
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

bool Router::addDevice(Device* devicePtr)
{
	// 检查有无空接口
	// ...
	// 根据连的是何种设备来更新路由表
	// 电脑：
	// newRoute = Route(ip, ip, 上面分配到的新itf)
	// 把该电脑的itf指向该路由器
	// 
	// 路由器
	// 两个路由器的路由表互相合并(x)
	// 各新增一条指向对方的路由
	// 5 itfs at most
	if (freeItf() != -1)
	{
		int index = freeItf();
		//std::cout << "Interface" << index << " is available" << std::endl;
		itfs[index].devicePtr = devicePtr;
		Router* routingPtr = dynamic_cast<Router*>(itfs[index].devicePtr);
		if (routingPtr != nullptr) // if router
		{
			if (int anotherIndex = routingPtr->freeItf()) // check if another router has a free interface
			{
				auto originalRoutingTable = routingTable;
				// merging table
				for (auto const& route : routingPtr->routingTable)
				{
					auto newRoute = Route(route.end, routingPtr->getAddress(), itfs[index]);
					routingTable.push_back(newRoute);
				}
				for (auto const& route : originalRoutingTable)
				{
					auto newRoute = Route(route.end, getAddress(), itfs[anotherIndex]);
					routingPtr->routingTable.push_back(newRoute);
				}
				// adding new route respectively
				Route newRoute1 = Route(devicePtr->getAddress(), devicePtr->getAddress(), itfs[index]);
				routingTable.push_back(newRoute1);
				Route newRoute2 = Route(getAddress(), getAddress(), routingPtr->itfs[anotherIndex]);
				routingPtr->routingTable.push_back(newRoute2);
				return true;
				std::cout << "Router " << routingPtr->getName() << " connected to the "
					<< itfs[index].name << " of Router " << getName() << std::endl;
			}
			else
			{
				std::cout << "No interface availble, failed to add device." << std::endl;
				return false;
			}
		}
		else // computer (or device)
		{
			Computer* computerPtr = dynamic_cast<Computer*>(itfs[index].devicePtr);
			if (computerPtr != nullptr)
			{
				Route newRoute = Route(computerPtr->getAddress(), computerPtr->getAddress(), itfs[index]);
				routingTable.push_back(newRoute);

				std::cout << "Computer " << computerPtr->getName() << " connected to the "
					<< itfs[index].name << " of Router " << getName() << std::endl;
				return true;
			}
		}
	}

	std::cout << "No interface availble, failed to add device." << std::endl;
	return false;
}

void Router::printRoutingTable() const
{
	std::cout << "Routing Table of Router " << getName() << ": " << std::endl;
	std::cout << "Destination        NextHop            Interface" << std::endl;
	std::cout.setf(std::ios::left);
	for (std::vector<Route>::const_iterator it = routingTable.begin(); it != routingTable.end(); it++)
	{
		std::cout << std::setw(19) << it->end
			<< std::setw(19) << it->nextHop
			<< std::setw(19) << it->itf.name
			<< std::endl;
	}
}

int Router::freeItf() const
{
	for (int i = 0; i < 5; ++i)
	{
		if (itfs[i].devicePtr == nullptr)
			return i;
	}
	return -1;
}


