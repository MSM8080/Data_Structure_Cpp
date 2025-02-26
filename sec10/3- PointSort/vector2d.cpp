#include "vector2d.h"
#include <cmath>
#include <cstdlib>

Vector2D::Vector2D (float _x,float _y): y(_y),x(_x) {}

Vector2D::Vector2D (): y(0),x(0) {}

float& Vector2D::x_comp() { return x;}

float& Vector2D::y_comp() { return y;}

float Vector2D::dotProduct(Vector2D v) {return x*v.x+y*v.y;}

void Vector2D::normalize(){
    float l=(float)sqrt(x*x+y*y);
    x/=l;
    y/=l;
}

Vector2D Point::operator-( Point p) const
{return Vector2D(x-p.x,y-p.y);} 