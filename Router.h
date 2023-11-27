#pragma once
#include "Device.h"
#include <vector>

class Route
{
public:
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

