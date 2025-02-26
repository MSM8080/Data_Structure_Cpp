#include <iostream>
#include "../complex.h"
using namespace std;

int main()
{
//
//    cout << "= " <<  power(2,10)<< endl;
//    cout << "= " <<  power(2.1,4)<< endl;
//    cout << "= " <<  power(2.5f,4)<< endl;
//

    Complex c1(2,5);
    c1.polar_form();
    c1.print_algebra();
    cout<<endl;
    c1.print_polar();
    cout<<endl;
    c1.power_complex(5);
    c1.print_algebra();
    cout<<endl;

    return 0;
}
