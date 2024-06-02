#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <ncurses.h>
#include "Board.h"
#include "Growth.h"
#include "Snake.h"
#include "Scoreboard.h"
#include "Poison.h"
#include "Gate.h"
#include "MissionBoard.h"
#include "Mission.h"
#include "Speedup.h"
#include "Speeddown.h"

class SnakeGame
{
    Board board;
    bool game_over;
    Growth* growth;
    Poison* poison;
    Gate* gate[2];
    Speedup* speedup;
    Speeddown* speeddown;
    Snake snake;
    int gate_c;

    Scoreboard scoreboard;
    MissionBoard missionboard;
    Mission mission;
    int maxLength;
    int score;
    int length;
    int growth_item;
    int poison_item;
    int gate_item;
    int b;
    int time_s;
    int stage;
    int new_wall;

    int speedup_n;
    int view_speed;

    void handleNextPiece(SnakePiece next); // ��� �Ծ��� �� Ŀ����
    void createGrowth(); // ��� ���� �Լ�
    void createPoison();
    void createSpeedup();
    void createSpeeddown();
    void createGate();
    void createWall(int y, int x); // �� ���� �Լ�
    void createImmWall(int y, int x);
    void createMap();
    void createMap2();
    void createMap3();
    void createMap4();
    void eatGrowth();
    void eatPoison();
    void eatSpeedup();
    void eatSpeeddown();
    void eatGate();
    void eatTime();

public:
    SnakeGame(int height, int width, int speed = 300);
    ~SnakeGame();
    void initialize(); //
    void processInput(); // ����ڿ��� �Է� ����
    void updateState(); //
    void redraw();
    bool isOver();
    int getScore();

};

#endif 