#include "And.h"
#include "Or.h"
#include "Not.h"
#include "Xor.h"
#include "FullAdder.h"

// #define TestCase0 // TruthTable (And, Or, Not)
// #define TestCase1 // Xor
// #define TestCase2 // FullAdder

int main()
{
    enum {XorInputCount=3, TableSize=8};
    int lgtt_array[TableSize]= {0};
    int lgtt=36;
    bool lgtc=0;
    bool xortc=0;
    bool fatc=0;
    //LogicCircuitTruthTable
    bool xyzInput[3];
    Not n1, n2, n3;
    And a1(3), a2(3);
    Or f(2);
#ifdef TestCase0
    for(int i=0; i<TableSize; i++)
    {
        for (int inputIndex=0; inputIndex<3; inputIndex++)
            xyzInput[inputIndex] = i & (1<<inputIndex);

        n1.setInput(xyzInput[0]);
        n2.setInput(xyzInput[2]);
        n3.setInput(xyzInput[1]);

        a1.setInput(0, n1.output());
        a1.setInput(1, xyzInput[1]);
        a1.setInput(2, n2.output());
        a2.setInput(0, xyzInput[0]);
        a2.setInput(1, n3.output());
        a2.setInput(2, xyzInput[2]);

        f.setInput(0, a1.output());
        f.setInput(1, a2.output());
        lgtt_array[i]=f.output();
    }
    //EndOfLogicCircuitTruthTable
    lgtc=true;
    cout<<"Logic Circuit TruthTable.\n";
    for (int i=0; i<TableSize; i++)
    {
        bool val=lgtt & (1<<i);
        if(lgtt_array[i]!=val)
        {
            cout<<"TestCase0: failed. \n\n\n";
            lgtc=false;
            break;
        }
    }
    if(lgtc)
        cout<<"TestCase0: passed. \n\n\n";
#endif
    /*------------------------------------------------------------*/
    /*------------------------------------------------------------*/
#ifdef TestCase1
    Xor xorgate(XorInputCount);
    cout<<"Xor TruthTable.\n";
    for (int i=0; i<TableSize; i++)
    {
        for (int inputIndex=0; inputIndex<XorInputCount; inputIndex++)
        {
            bool val = i & (1<<inputIndex);
            // initialize xortc
            if(!inputIndex)
                xortc=val;
            else
                xortc^=val;
            xorgate.setInput(inputIndex, val);
        }
        if(xorgate.output()!=xortc)
        {
            cout<<"TestCase1: failed. \n\n\n";
            xortc=false;
            break;
        }
        // do not move this line.
        xortc=true;
    }
    if(xortc)
        cout<<"TestCase1: passed. \n\n\n";
#endif
    /*------------------------------------------------------------*/
    /*------------------------------------------------------------*/
#ifdef TestCase2
    FullAdder fa;
    cout<<"FullAdder TruthTable.\n";
    for (int i=0; i<TableSize; i++)
    {
        int mathSum=0;
        bool carryBit=0, sumBit=0;
        for (int inputIndex=0; inputIndex<XorInputCount; inputIndex++)
        {
            bool val = i & (1<<inputIndex);
            mathSum+=val;
            fa.setInput(inputIndex, val);
        }
        carryBit=mathSum>>1;
        sumBit=mathSum&1;
        if(fa.carry()!=carryBit  || fa.sum()!= sumBit)
        {
            cout<<"TestCase2: failed. \n\n\n";
            fatc=false;
            break;
        }
        fatc=true;
    }
    if(fatc)
        cout<<"TestCase2: passed. \n\n\n";
#endif
    return 0;
}














/** Arithmetic +-/*% **/
/** Arithmetic += -= /= *= **/
/** Compare > >= < <= != == **/
/** Input/Output cin cout **/
/** **/


/**Keyboard shortcuts **/
/**Plugins**/
/**Source code formatter (AStyle)**/
/**ctrl shift i**/
