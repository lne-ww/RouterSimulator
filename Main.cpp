#include <iostream>
#include "Router.h"
#include "Network.h"

using namespace std;

int main()
{
	//construct network
	Router* r1 = new Router("192.168.1.1", "r1");
	Computer* pc1 = new Computer("192.168.1.2", "pc1", "pc1 interface", r1);
	Computer* pc2 = new Computer("192.168.1.3", "pc2", "pc2 interface", r1);
	Computer* pc3 = new Computer("192.168.1.4", "pc3", "pc3 interface", r1);
	Network* n1 = new Network(r1);
	n1->addComputer(pc1);
	n1->addComputer(pc2);
	n1->addComputer(pc3);

	Router* r2 = new Router("10.1.1.1", "r2");
	Computer* pc4 = new Computer("10.1.1.2", "pc4", "pc4 interface", r2);
	Computer* pc5 = new Computer("10.1.1.3", "pc5", "pc5 interface", r2);
	Network* n2 = new Network(r2);
	n2->addComputer(pc4);
	n2->addComputer(pc5);

	n1->info();
	n2->info();
	
	n1->connect(*n2);
	r1->printRoutingTable();
	r2->printRoutingTable();

	//simulate the process of sending packet
	Packet p("192.168.1.1", "10.1.1.2", "I love C++");
	pc1->send(p);
}