#include "Transport.h"

#ifndef Taxi_Header
#define Taxi_Header


class Taxi:public Transport
{
	string driverName;
public:
	Taxi(string src, string dst, float speed, string driverName_);
	void print();
};

#endif