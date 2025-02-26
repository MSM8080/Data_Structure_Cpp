#include "Gate.h"

#ifndef And_Header
#define And_Header

// An "And" Gate with noi inputs
// It stores no more data
class And : public Gate
{
public:
	And(int noi);
	bool output();
};

#endif
