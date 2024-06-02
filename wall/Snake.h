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
    SnakePiece(int y, int x); //snake 생성과 위치 설정
};

// class SnakeHead : public SnakePiece
// {
// public: 
//     SnakeHead() ;
//     SnakeHead(int y, int x) ; //snake 생성과 위치 설정
// } ;

class Snake
{

    Direction cur_direction; // 현재 방향 상태를 저장

public:
    Snake();
    void addPiece(SnakePiece piece); // snake 조각을 snake에 추가
    void removePiece(); // snake 조각을 삭제(꼬리를 삭제)
    SnakePiece tail(); // 꼬리값 반환
    SnakePiece head(); // head 값 반환
    Direction getDirection(); //현재 방향 반환
    int setDirection(Direction d);
    SnakePiece nextHead(); // 현재 head를 이용해서 다음 head를 계산
    int getSize();

    deque<SnakePiece> prev_pices; //snake 조각을 저장하는 queue(snake)

};

#endif