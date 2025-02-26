#include "Or.h"

// noi : Number of inputs
// Constructor to make a "Gate" with noi inputs
Or::Or(int noi) : Gate(noi)
{}

// function that returns the output of the Gate
bool Or::output()
{
    bool val = getInput(0);
    for(int i=1; i<getNumberOfInputs(); i++)
    {
        val = val || getInput(i);
    }
    return val;
}
