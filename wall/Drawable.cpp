#include "Drawable.h"

Drawable::Drawable()
{
    y = x = 0;
    icon = ' ';
    toggle = 0;
}

Drawable::Drawable(int y, int x, chtype ch)
{
    this->y = y;
    this->x = x;
    this->icon = ch;
    toggle = 0;
    r = 50;
}

int Drawable::getX()
{
    return x;
}

int Drawable::getY()
{
    return y;
}

chtype Drawable::getIcon()
{
    return icon;
}

void Drawable::setYX(int y, int x)
{
    this->y = y;
    this->x = x;
}