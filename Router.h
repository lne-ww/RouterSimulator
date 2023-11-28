#pragma once
#include "Device.h"
#include <vector>

class Route
{
public:
    Route(std::string _end, std::string _nextHop, std::string _itfName, Device* ptr);
    std::string end;
    std::string nextHop;
    std::string itfName;
    Device* devicePtr;
};

class Router :
    public Device
{
public:
    Router();
    virtual bool send(Packet p) override;
private:
    std::vector<Route> routingTable;
};
