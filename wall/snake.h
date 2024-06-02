#ifndef SNAKE_H
#define SNAKE_H
#include <ncurses.h>
#include "Drawable.h"
#include <deque> 
using namespace std;

enum Direction
{
    up = -1,
    down = 1,
    left = -2,
    right = 2
};

class SnakePiece : public Drawable
{
public:
    SnakePiece();
    SnakePiece(int y, int x); //snake ������ ��ġ ����
};

// class SnakeHead : public SnakePiece
// {
// public: 
//     SnakeHead() ;
//     SnakeHead(int y, int x) ; //snake ������ ��ġ ����
// } ;

class Snake
{

    Direction cur_direction; // ���� ���� ���¸� ����

public:
    Snake();
    void addPiece(SnakePiece piece); // snake ������ snake�� �߰�
    void removePiece(); // snake ������ ����(������ ����)
    SnakePiece tail(); // ������ ��ȯ
    SnakePiece head(); // head �� ��ȯ
    Direction getDirection(); //���� ���� ��ȯ
    int setDirection(Direction d);
    SnakePiece nextHead(); // ���� head�� �̿��ؼ� ���� head�� ���
    int getSize();

    deque<SnakePiece> prev_pices; //snake ������ �����ϴ� queue(snake)

};

#endif