#include "And.h"

// noi : Number of inputs
// Constructor that make a "Gate" with noi inputs
And::And(int noi) : Gate(noi)
{}

// function that return the output of the Gate
bool And::output()
{
    bool val = getInput(0);
    for(int i=1; i<getNumberOfInputs(); i++)
    {
        val = val && getInput(i);
    }
    return val;
}

