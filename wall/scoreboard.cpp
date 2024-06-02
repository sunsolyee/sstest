#include "Scoreboard.h"


Scoreboard::Scoreboard()
{

}

Scoreboard::Scoreboard(int width, int y, int x)
{
    score_win = newwin(10, width / 3, y, x);
    box(score_win, 0, 0);
}

void Scoreboard::initialize(int initial_score, int initial_length, int initial_poison, int initial_apple, int initial_gate, int time_e, int speed_n)
{
    clear();
    mvwprintw(score_win, 1, 2, "     Score Board");
    mvwprintw(score_win, 2, 2, "B:");
    mvwprintw(score_win, 3, 2, "+:");
    mvwprintw(score_win, 4, 2, "-:");
    mvwprintw(score_win, 5, 2, "G:");
    mvwprintw(score_win, 7, 2, "time:");
    mvwprintw(score_win, 6, 2, "speed:");
    // updateScore(initial_score) ;
    updateLength(initial_length);
    updateGrowth(initial_growth);
    updatePoison(initial_poison);
    updateGate(initial_gate);
    updateTime(time_e);
    updateSpeed(speedup_n);

    refresh();
}

// void scoreboard::updateScore(int score) 
// {
//     mvwprintw(score_win, 1, score_win->_maxx-5 , "%i", score) ;
// }

void Scoreboard::updateLength(int length) {
    mvwprintw(score_win, 2, score_win->_maxx - 5, "%i", length);
}
void Scoreboard::updateGrowth(int apple) {
    mvwprintw(score_win, 3, score_win->_maxx - 5, "%i", growth);
}
void Scoreboard::updatePoison(int poison) {
    mvwprintw(score_win, 4, score_win->_maxx - 5, "%i", poison);
}
void Scoreboard::updateGate(int gate) {
    mvwprintw(score_win, 5, score_win->_maxx - 5, "%i", gate);
}
void Scoreboard::updateTime(int time_e) {
    mvwprintw(score_win, 7, score_win->_maxx - 5, "%i", time_e);
}

void Scoreboard::updateSpeed(int speeupd_n)
{
    mvwprintw(score_win, 6, score_win->_maxx - 5, "%i", speedup_n);
}

void Scoreboard::clear()
{
    wclear(score_win);
}

void Scoreboard::refresh()
{
    wrefresh(score_win);
}