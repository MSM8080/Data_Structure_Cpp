#include "Transport.h"

#ifndef Ship_Header
#define Ship_Header

class Ship:public Transport
{
	public:
	Ship(string src, string dst);
	bool has_available_space();
	int book();
	void print();
};

#endif