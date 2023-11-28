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


Route::Route(std::string _end, std::string _nextHop, const Itf& itf)
	: end(_end), nextHop(_nextHop), itf(itf)
{
}

Router::Router(std::string _address, std::string _name)
	: Device(_address, _name), routingTable(), itfs()
{
	for(int i = 0; i < 5; i++)
	{
		itfs[i].name = "interface" + i;
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

void Router::addDevice(Device* ptr)
{
	// 检查有无空接口
	// ...
	// 根据连的是何种设备来更新路由表
	// 电脑：
	// newRoute = Route(ip, ip, 上面分配到的新itf)
	// 把该电脑的itf指向该路由器
	// 
	// 路由器
	// 两个路由器的路由表互相合并
	// 各新增一条指向对方的路由
	// 
	// 
	// 
	Route r()
	
}


