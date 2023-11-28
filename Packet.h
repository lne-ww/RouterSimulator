#pragma once
#include <string>
#include <iostream>
class Packet
{
	friend std::ostream& operator<<(std::ostream& output, const Packet p);
public:

	Packet(std::string _start, std::string _end, std::string _payload);
	std::string start;
	std::string end;
	std::string payload;
};

