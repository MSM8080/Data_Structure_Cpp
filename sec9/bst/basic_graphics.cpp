#include "basic_graphics.h"


/*
 * special characters:
 * 22(0x16):h_var
 * 221(0xDD):wide_sl_v_bar 222(0xDE): wide_sr_v_bar
 */

int x0 = 1;
int y0 = 1;
int x_scale = 5;
int y_scale = 3;
int offset = 1;
int max_depth = 5;

const char r_vbar = '\xDD';
const char l_vbar = '\xDE';
const char h_bar = '\x16';

void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void draw_node(Elem data, int x, int y)
{
    int edge_width = 0;
    /* scaling */
    x = x_scale * (x+x0);
    y = y_scale * (y+y0);
    /* horizontal edge width */
    for (Elem d = data; d>0; edge_width++)
        d /= 10;
    /* horizontal edges */
    for (int i=0; i<2; i++)
    {
        // upper edge position
        if(i==0) {gotoxy(x, y-offset);}
        // lower edge position
        else     {gotoxy(x, y+offset);}
        for (int j=0; j<edge_width+2; j++)
            cout << (i==0?h_bar:h_bar);
    }
    gotoxy(x, y);
    /* vertical edges and data */
    cout << r_vbar << data << l_vbar;

}
