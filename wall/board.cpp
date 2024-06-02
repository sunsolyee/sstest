#include <ncurses.h>
#include "Board.h"
#include <iostream>
#include "Time.h"

Board::Board()
{
    construct(0, 0, 300);
}

Board::Board(int height, int width, int speed)
{
    construct(height, width, speed);
    // initialize() ;
}

void Board::initialize()
{
    clear();
    refresh();
}

void Board::addBorder()
{
    box(board_win, 0, 0);
}

void Board::add(Drawable drawable)
{
    addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
}

void Board::addAt(int y, int x, chtype ch)
{
    mvwaddch(board_win, y, x, ch);
}

void Board::getEmptyCoordinates(int& y, int& x)
{
    while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != ' '); // 빈문자를 찾기(빈 문자가 있으면 멈춤)

}

void Board::getWallCoordinates(int& y, int& x)
{
    while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != '.'); // 빈문자를 찾기(빈 문자가 있으면 멈춤)

}

chtype Board::getCharat(int y, int x)
{
    return mvwinch(board_win, y, x);
}

chtype Board::getInput()
{
    time_t time_last_input = Time::milliseconds(); //처음 이 함수 들어왔을 때 시간

    chtype input = wgetch(board_win);
    chtype new_input = ERR;

    setTimeout(0);
    while (time_last_input + timeout >= Time::milliseconds()) //기다려야되는 시간이 될때까지 기다리기
    {
        new_input = wgetch(board_win); // 기다리는 동안 받은 input
    }
    setTimeout(timeout);

    if (new_input != ERR) // 기다리는 동안 새로 들어온 input이 있으면
        input = new_input;

    return input;
    // return wgetch(board_win) ;
}

void Board::clear()
{
    wclear(board_win);
    addBorder();
}

void Board::refresh()
{
    wrefresh(board_win);
}

void Board::construct(int height, int width, int speed) // board 설정
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax); // stdscr의 최대 x랑 최대 y를 반환

    //빈 좌표를 가져오기 위함?
    this->height = height;
    this->width = width;

    start_row = (yMax / 2) - (height / 2);
    start_col = (xMax / 2) - (width / 2);

    board_win = newwin(height, width, start_row, start_col);
    timeout = speed;

    setTimeout(speed); // 윈도우의 입력 대기 시간을 설정, 입력을 1초 기다리고 아무 입력도 없으면 그냥 실행

    keypad(board_win, true); // 특수 키(확장된 키보드 키 또는 함수 키)를 입력으로 받을 수 있도록 하는 모드
}

void Board::setTimeout(int timeout)
{
    wtimeout(board_win, timeout);
}

int Board::getTimeout()
{
    return timeout;
}

int Board::getStartRow()
{
    return start_row;
}

int Board::getStartCol()
{
    return start_col;
}

int Board::getWidth()
{
    return width;
}
int Board::getHeight()
{
    return height;
}