#pragma once
#include "Device.h"
#include "Packet.h"
#include "Router.h"

class Computer :
    public Device
{
public:
    Computer();
    virtual bool send(Packet p) override;

    
private:
    std::string itf; // interface
    Router* routerPtr;
};

