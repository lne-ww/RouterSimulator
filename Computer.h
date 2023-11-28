#pragma once
#include "Device.h"
#include "Packet.h"
#include "Router.h"

class Computer :
    public Device
{
public:
    Computer(std::string, Router*);
    virtual bool send(Packet p) const override;
    virtual bool receive(Packet p) const override;
    
private:
    std::string itf; // interface
    Router* routerPtr; // the router it connects
};

