#include "MissionBoard.h"


MissionBoard::MissionBoard()
{

}

MissionBoard::MissionBoard(int width, int y, int x)
{
    mission_win = newwin(8, width / 2, y, x);
    box(mission_win, 0, 0);
}

void MissionBoard::initialize(char initial_length, char initial_growth, char initial_poison, char initial_gate, char initial_speedup)
{
    clear();
    mvwprintw(mission_win, 1, 2, "     Mission");
    mvwprintw(mission_win, 2, 2, "B:");
    mvwprintw(mission_win, 3, 2, "+:");
    mvwprintw(mission_win, 4, 2, "-:");
    mvwprintw(mission_win, 5, 2, "G:");
    mvwprintw(mission_win, 6, 2, "S:");
    updateLength(initial_length);
    updateApple(initial_growth);
    updatePoison(initial_poison);
    updateGate(initial_gate);
    updateSpeed(initial_speedup);

    refresh();
}

void MissionBoard::updateLength(char length) {
    mvwprintw(mission_win, 2, mission_win->_maxx - 5, "(%c)", length);
}
void MissionBoard::updateGrowth(char apple) {
    mvwprintw(mission_win, 3, mission_win->_maxx - 5, "(%c)", growth);
}
void MissionBoard::updatePoison(char poison) {
    mvwprintw(mission_win, 4, mission_win->_maxx - 5, "(%c)", poison);
}
void MissionBoard::updateGate(char gate) {
    mvwprintw(mission_win, 5, mission_win->_maxx - 5, "(%c)", gate);
}
void MissionBoard::updateSpeed(char speedup) {
    mvwprintw(mission_win, 6, mission_win->_maxx - 5, "(%c)", speedup);
}

// void Scoreboard::updateScore(int score) 
// {
//     mvwprintw(score_win, 1, score_win->_maxx-5 , "%i", score) ;
// }

// void Scoreboard::updateLength(int length){
//     mvwprintw(score_win, 2, score_win->_maxx-5, "%i", length) ;
// }
// void Scoreboard::updateApple(int apple){
//     mvwprintw(score_win, 3, score_win->_maxx-5, "%i", apple) ;
// }
// void Scoreboard::updatePoison(int poison){
//     mvwprintw(score_win, 4, score_win->_maxx-5, "%i", poison) ;
// }
// void Scoreboard::updateGate(int gate){
//     mvwprintw(score_win, 5, score_win->_maxx-5, "%i", gate) ;
// }
// void Scoreboard::updateTime(int time_e){
//     mvwprintw(score_win, 6, score_win->_maxx-5, "%i", time_e) ;
// }

void MissionBoard::clear()
{
    wclear(mission_win);
}

void MissionBoard::refresh()
{
    wrefresh(mission_win);
}