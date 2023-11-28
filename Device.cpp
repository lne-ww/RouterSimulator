#include "Device.h"

Device::Device()
	: address(""), name("")
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
