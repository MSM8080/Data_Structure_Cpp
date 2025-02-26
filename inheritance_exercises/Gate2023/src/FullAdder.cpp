#include "FullAdder.h"
/*
 * FullAdder Block: performs binary addition
 * of 2 binary digits plus a carry-in digit.
 * inputs: A, B, Cin
 * outputs: Cout, Sum
 * Sum = A XOR B XOR Cin;
 * Cout = (A AND B) OR (Cin AND (A XOR B));
*/
// constructor that constructs a gate (block) with appropriate #inputs.
FullAdder::FullAdder() : Gate(3)
{}
// sum function that returns the output sum of the full adder.
bool FullAdder::sum()
{
    bool a,b,c,ab,s;
    a = getInput(0);
    b = getInput(1);
    c = getInput(2);
    ab =  a ^ b;
    s = ab ^ c;
    return s;
}
// carry function that returns the output carry of the full adder.
bool FullAdder::carry()
{
    bool a,b,c,and1,and2,carry;
    a = getInput(0);
    b = getInput(1);
    c = getInput(2);
    and1 = c && (a ^ b);
    and2 =  a && b;
    carry = and1 || and2;
    return carry;
}
