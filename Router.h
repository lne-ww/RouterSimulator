#pragma once
#include "Device.h"
#include <vector>
#include <array>

class Route
{
public:
    Route(std::string _end, std::string _nextHop, const Itf& itf);
    std::string end;
    std::string nextHop;
    Itf itf;
};

class Router :
    public Device
{
public:
    Router(std::string _address, std::string _name);
    virtual bool send(Packet p) const override;
    virtual bool receive(Packet p) const override;
    void addDevice(Device* ptr); // connnect in physical way
    Itf* getItfs() { return itfs; }
    void printRoutingTable() const;

private:
    std::vector<Route> routingTable;
    Itf itfs[5];
};
