#pragma once
#include <string>
#include "Packet.h"

class Device
{
public:
	Device(std::string _address, std::string _name);
	std::string getAddress() const;
	std::string getName() const;
	virtual bool send(Packet p) const = 0;
	virtual bool receive(Packet p) const = 0;

private:
	std::string address;
	std::string name;
};

class Itf
{
public:
	Itf();
	Itf(std::string _name, Device* _devicePtr);

	std::string name;
	Device* devicePtr;
};
