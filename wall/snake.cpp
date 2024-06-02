#include "Snake.h"
#include <deque>
#include <iostream>

SnakePiece::SnakePiece() : Drawable(0, 0, '#') {}

SnakePiece::SnakePiece(int y, int x) : Drawable(y, x, '#') {}

// SnakeHead::SnakeHead() {
//     Drawable(0, 0, 'H') ;
// }
// SnakeHead::SnakeHead(int y, int x) {
//     Drawable(y, x, 'H');
// }

Snake::Snake()
{
    cur_direction = down;
}
void Snake::addPiece(SnakePiece piece)
{
    // prev_pices.back().icon =  'x';
    // std::cout << prev_pices.back().icon << std::endl ;
    prev_pices.push_back(piece);
}
void Snake::removePiece()
{
    prev_pices.pop_front();
}
SnakePiece Snake::tail()
{
    return prev_pices.front();
}
SnakePiece Snake::head()
{
    return prev_pices.back();
}
Direction Snake::getDirection()
{
    return cur_direction;
}
int Snake::setDirection(Direction d)
{
    if (cur_direction + d != 0) // 반대 방향으로 안 가게 해줌
    {
        cur_direction = d;
        return 0;
    }
    else
        return 1;
}
SnakePiece Snake::nextHead()
{
    int row = head().getY();
    int col = head().getX();

    switch (cur_direction)
    {
    case down:
        row++;
        break;
    case up:
        row--;
        break;
    case Direction::left:
        col--;
        break;
    case Direction::right:
        col++;
        break;
    }

    return SnakePiece(row, col);
}

int Snake::getSize()
{
    return prev_pices.size();
}