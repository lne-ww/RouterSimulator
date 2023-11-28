#pragma once
#include "Device.h"
#include "Packet.h"
#include "Router.h"

class Computer :
    public Device
{
public:
    Computer(std::string);
    virtual bool send(Packet p) override;
    bool receive(Packet p);
    
private:
    std::string itf; // interface
    Router* routerPtr;
};

