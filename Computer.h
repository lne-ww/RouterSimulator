#pragma once
#include "Device.h"
#include "Packet.h"
#include "Router.h"

class Computer :
    public Device
{
public:
    Computer(std::string _address, std::string _name, const Itf& itf);
    virtual bool send(Packet p) const override;
    virtual bool receive(Packet p) const override;
    Itf getItf() const;
private:
    Itf itf;
};

