#include "Gate.h"

// noi : Number of inputs
// Constructor to create "input" array and initiate all inputs to false
Gate::Gate(int noi) : n(noi)
{
    input = new bool(n);
    for(int i =0 ; i<n; i++)
    {
        input[i] = false;
    }
}

//sets the input with index "ind" to the value "value"
void Gate::setInput(int ind,bool value)
{
    input[ind] = value;
}

//returns the value of input with index "ind"
bool Gate::getInput(int ind)
{
    return input[ind];
}

//returns the total number of inputs
int Gate::getNumberOfInputs()
{
    return n;
}
