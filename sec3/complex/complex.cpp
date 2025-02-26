#include"complex.h"
#include <math.h>
// ----------------------------------------------
Complex::Complex(float r, float i)
: real(r), imag(i)
{
    magnitude = 0;
    theta = 0;
}
//  ----------------------------------------------
void Complex::print_algebra()
{
	cout<<real;
	if(imag==0) return;
	if(imag<0) { cout<<"-j"<< -imag<<endl;}
	else { cout<<"+j"<<imag;}
}
// ----------------------------------------------
void Complex::print_polar()
{
	cout<<"|"<<magnitude<<"| < "<<theta<<"(angle)"<<endl;
}
// ----------------------------------------------
void Complex::polar_form()
{
    magnitude = sqrt(power(real,2)+power(imag,2));
    if(real>0 && imag>0)
    {
        theta = (180/3.141592654)*atan(imag/real);
    }
    else if(real<0 && imag>0)
    {
        theta =180 - ((180/3.141592654)*atan(imag/-real));
    }
    else if(real<0 && imag<0)
    {
        theta = 180 + (180/3.141592654)*atan(-imag/-real);
    }
    else if(real>0 && imag<0)
    {
        theta =360 - (180/3.141592654)*atan(-imag/real);
    }
}
// ----------------------------------------------
void Complex::power_complex(int b)
{
    theta = theta*b;
    if (theta>360)
        theta -=360;
    magnitude = power(magnitude,b);
    cartesien_form();

}
// ----------------------------------------------
void Complex::cartesien_form()
{
    real = magnitude*cos(theta*(3.141592654/180));
    imag = magnitude*sin(theta*(3.141592654/180));
}


