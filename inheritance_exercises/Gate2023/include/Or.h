#include "Gate.h"

#ifndef Or_Header
#define Or_Header

// An "Or" gate with noi input
// It stores no more data
class Or : public Gate
{
public:
	Or(int noi);
	bool output();
};

#endif
