#ifndef POISON_H
#define POISON_H
#include <ncurses.h>
#include "Drawable.h"

class Poison : public Drawable
{
public:
    Poison(int y, int x);
};

#endif 