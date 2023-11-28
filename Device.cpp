#include "Device.h"


Itf::Itf() : name(""), devicePtr(nullptr)
{
}

Itf::Itf(std::string _name, Device* _devicePtr)
	: name(_name), devicePtr(_devicePtr)
{
}


Device::Device(std::string _address, std::string _name)
	: address(_address), name(_name)
{
}

std::string Device::getAddress() const
{
	return address; 
}

std::string Device::getName() const
{
	return name;
}
