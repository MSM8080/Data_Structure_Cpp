#include "Transport.h"

#ifndef Bus_Header
#define Bus_Header


class Bus:public Transport
{
	string driverName;
public:
	Bus(string src, string dst, int type, string driverName_);
	void print();
};

#endif