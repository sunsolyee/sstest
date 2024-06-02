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
    while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != ' '); // ���ڸ� ã��(�� ���ڰ� ������ ����)

}

void Board::getWallCoordinates(int& y, int& x)
{
    while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != '.'); // ���ڸ� ã��(�� ���ڰ� ������ ����)

}

chtype Board::getCharat(int y, int x)
{
    return mvwinch(board_win, y, x);
}

chtype Board::getInput()
{
    time_t time_last_input = Time::milliseconds(); //ó�� �� �Լ� ������ �� �ð�

    chtype input = wgetch(board_win);
    chtype new_input = ERR;

    setTimeout(0);
    while (time_last_input + timeout >= Time::milliseconds()) //��ٷ��ߵǴ� �ð��� �ɶ����� ��ٸ���
    {
        new_input = wgetch(board_win); // ��ٸ��� ���� ���� input
    }
    setTimeout(timeout);

    if (new_input != ERR) // ��ٸ��� ���� ���� ���� input�� ������
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

void Board::construct(int height, int width, int speed) // board ����
{
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax); // stdscr�� �ִ� x�� �ִ� y�� ��ȯ

    //�� ��ǥ�� �������� ����?
    this->height = height;
    this->width = width;

    start_row = (yMax / 2) - (height / 2);
    start_col = (xMax / 2) - (width / 2);

    board_win = newwin(height, width, start_row, start_col);
    timeout = speed;

    setTimeout(speed); // �������� �Է� ��� �ð��� ����, �Է��� 1�� ��ٸ��� �ƹ� �Էµ� ������ �׳� ����

    keypad(board_win, true); // Ư�� Ű(Ȯ��� Ű���� Ű �Ǵ� �Լ� Ű)�� �Է����� ���� �� �ֵ��� �ϴ� ���
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