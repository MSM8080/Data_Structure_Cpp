#include "Gate.h"

#ifndef Xor_Header
#define Xor_Header

// An "Xor" gate with noi inputs
// It stores no more data
class Xor : public Gate
{
public:
	Xor(int noi);
	bool output();
};

#endif
