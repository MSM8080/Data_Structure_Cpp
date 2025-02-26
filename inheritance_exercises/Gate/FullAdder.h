#include "Gate.h"

#ifndef FullAdder_Header
#define FullAdder_Header

// FullAdder block (3 inputs, 2 outputs)
class FullAdder : public Gate
{
public:
	// Constructor that constructs a gate (block) with 3 inputs.
    FullAdder();
    // sum function that returns the output sum of the full adder.
    bool sum();
    // carry function that returns the output carry of the full adder.
    bool carry();
};

#endif
