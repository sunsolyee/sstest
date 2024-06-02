#ifndef MISSIONBOARD_H
#define MISSIONBOARD_H
#include <ncurses.h>


class MissionBoard
{
    WINDOW* mission_win;
public:
    MissionBoard();
    MissionBoard(int width, int y, int x);
    void initialize(char initial_length, char initial_growth, char initial_poison, char initial_gate, char initial_speedup);
    void updateLength(char length);
    void updateGrowth(char growth);
    void updatePoison(char poison);
    void updateGate(char gate);
    void updateSpeed(char speed);
    void clear();
    void refresh();
};

#endif
