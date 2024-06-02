#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <ncurses.h>


class Scoreboard
{
    WINDOW* score_win;
public:
    Scoreboard();
    Scoreboard(int width, int y, int x);
    void initialize(int initial_score, int length, int initial_poison, int initial_growth, int initial_gate, int initial_time_e, int speedup_n);
    void updateScore(int score);
    void updateLength(int length);
    void updateGrowth(int growth);
    void updatePoison(int poison);
    void updateGate(int gate);
    void updateTime(int initial_time_e);
    void updateSpeedup(int speedup_n);
    void clear();
    void refresh();
};

#endif