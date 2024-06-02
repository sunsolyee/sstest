#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <ncurses.h>

class Drawable
{

public:
    Drawable();
    Drawable(int y, int x, chtype ch);
    int getX();
    int getY();
    chtype getIcon();
    void setYX(int y, int x);

    chtype icon;
    int y, x;
    int toggle;
    int r;


};

#endif 