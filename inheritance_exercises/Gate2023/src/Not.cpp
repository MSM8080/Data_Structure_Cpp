#include "Not.h"

// constructor to make a "Gate" with 1 input
Not::Not() : Gate(1)
{}

// function to set the value of the gate input
void Not::setInput(bool value)
{
    Gate::setInput(0,value);
}

// function to return the value of the gate input
bool Not::getInput()
{
    bool val;
    val = Gate::getInput(0);
    return val;
}

// function to return the value of the gate output
bool Not::output()
{
    bool val = !Not::getInput();
}
