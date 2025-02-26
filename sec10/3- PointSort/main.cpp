#include <iostream>
#include <string>
#include "vector2d.h"
using namespace std;



int main()
{
	Point p;
	Vector2D dir;
	Point ps[100];
	
	srand(10000);
	// (Vector) Normal to the line
	dir.x_comp()=(float)rand();
	dir.y_comp()=(float)rand();
	dir.normalize();

	// Point on the line
	p.x=rand()/1000.0f;
	p.y=rand()/1000.0f;

	// Random points
	for(int i=0;i<100;i++)
	{
		ps[i].x=rand()/1000.0f;
		ps[i].y=rand()/1000.0f;
	}

	return 0;
}

