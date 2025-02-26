#ifndef BASIC_GRAPHICS_H_INCLUDED
#define BASIC_GRAPHICS_H_INCLUDED
#include <iostream>
#include "windows.h"
#include <conio.h>

using namespace std;

typedef int Elem;

extern int x0;
extern int y0;
extern int x_scale;
extern int y_scale;
extern int offset;
extern int max_depth;

extern const char r_vbar;
extern const char l_vbar;
extern const char h_bar;

void gotoxy(int x, int y);

void draw_node(Elem data, int x, int y);


#endif // BASIC_GRAPHICS_H_INCLUDED
