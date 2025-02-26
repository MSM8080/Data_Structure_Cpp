#include "Gate.h"

#ifndef Not_Header
#define Not_Header

// A "Not" gate
// It stores no more data
// Remember that it has just one input.
// Note that it privately inherits Gate
class Not : private Gate
{
public:
	Not();
    void setInput(bool value);
	bool getInput();
	bool output();
};

#endif
