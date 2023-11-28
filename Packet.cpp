#include "Packet.h"

Packet::Packet(std::string _start, std::string _end, std::string _payload)
	:start(_start), end(_end), payload(_payload)
{
}

std::ostream& operator<<(std::ostream& output, const Packet p)
{
	output << "=========================Packet=========================" << std::endl;
	output << "start: " << p.start << std::endl;
	output << "end: " << p.end << std::endl;
	output << "payload: " << p.payload << std::endl;
	output << "========================================================" << std::endl;
	return output;
}
