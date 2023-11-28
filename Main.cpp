//Network n;
//Device a,b;
//n.addD(a) ... b;
//a.send(p)
//b.todo();
//SBDS
#include <iostream>
#include "Router.h"
#include "Network.h"

int main()
{
	Router* r1 = new Router("128.0.0.1", "r1");
	Computer c1("128.0.0.9", "c1", "c1 interface", r1);
	r1->addDevice(&c1);

}