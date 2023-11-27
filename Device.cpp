#include "Device.h"

Device::Device()
	: address(""), name("")
{
}

std::string Device::getAddress()
{
	return address; 
}

std::string Device::getName()
{
	return name;
}
