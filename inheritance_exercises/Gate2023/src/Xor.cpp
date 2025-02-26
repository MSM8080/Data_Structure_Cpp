#include "Xor.h"

// noi : Number of inputs
// constructor to make a "Gate" with noi inputs
Xor::Xor(int noi) : Gate(noi)
{}

//function that returns the output of the Gate
bool Xor::output()
{
    bool val = getInput(0);
    for(int i=1; i<getNumberOfInputs(); i++)
    {
        val = val ^ getInput(i);
    }
    return val;
}
