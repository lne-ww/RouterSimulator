#pragma once
#include <string>
#include "Packet.h"
class Device
{
public:
	Device();
	std::string getAddress();
	std::string getName();
	virtual bool send(Packet p) = 0; 

private:
	std::string address;
	std::string name;
};

