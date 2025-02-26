#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
    //float test;
    Matrix M1(5,5,Identity);
    M1.print();
    M1(0,0) = 100;
    cout<<endl;
    M1.print();
    return 0;
}
