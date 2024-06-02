#ifndef WALL_H
#define WALL_H

#include "Drawable.h"

class Wall : public Drawable
{
public:
    Wall(int y, int x);
};

class Immwall : public Drawable
{
public:
    Immwall(int y, int x);
};

#endif