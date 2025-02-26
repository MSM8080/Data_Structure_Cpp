#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>
#include <cstdlib>

class Vector2D
{ 
    private:
        float x;
        float y;
    public:
        Vector2D (float _x,float _y);
        Vector2D ();
        float& x_comp();
        float& y_comp();
        float dotProduct(Vector2D v);
        void normalize();
};

class Point{
    public:
        float x;
        float y;
        Vector2D operator-( Point p) const; 
};


#endif // VECTOR2D_H
