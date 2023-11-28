#pragma once
#include <string>
#include "Packet.h"
class Device
{
public:
	Device();
	std::string getAddress() const;
	std::string getName() const;
	virtual bool send(Packet p) const = 0;
	virtual bool receive(Packet p) const = 0;

private:
	std::string address;
	std::string name;
};

