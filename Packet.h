#pragma once
#include <string>
class Packet
{
public:
	Packet(std::string, std::string, std::string);
	std::string start;
	std::string end;
	std::string payload;
};

