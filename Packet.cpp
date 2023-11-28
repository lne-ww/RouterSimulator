#include "Packet.h"

Packet::Packet(std::string _start, std::string _end, std::string _payload)
	:start(_start), end(_end), payload(_payload)
{
}