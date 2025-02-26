#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;
// ----------------------------------------------
template <typename T>
T power(T a,int b)
{
    if(b==0)
        return 1;
    else if(b==1)
        return a;
    else
        return a* power(a,b-1);
}
// ----------------------------------------------
class Complex
{
private:
	float real;
	float imag;
	float theta;
	float magnitude;
public:
	Complex(float r, float i);
	void print_algebra();
    void print_polar();
    void polar_form();
	void print();
	void cartesien_form();
	void power_complex(int b);
};
#endif
