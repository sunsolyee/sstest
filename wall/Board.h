#ifndef BOARD_H
#define BOARD_H

#include "Drawable.h"

class Board
{
public:
    Board();
    Board(int height, int width, int speed);
    void initialize(); // 윈도우 초기화
    void addBorder(); // 테두리 생성
    void add(Drawable drawable); // Drawable 만들어서 문자 출력
    void addAt(int y, int x, chtype ch); //윈도우에 문자 출력(테두리 제외 x, y축 설정)
    void getEmptyCoordinates(int& y, int& x);
    void getWallCoordinates(int& y, int& x);
    chtype getCharat(int y, int x);
    chtype getInput(); // 사용자 입력 받기
    void clear(); //윈도우 지우기
    void refresh(); //윈도우 보이기
    void setTimeout(int timeout);
    int getTimeout();
    int getStartRow();
    int getStartCol();
    int getWidth();
    int getHeight();
    WINDOW* board_win;
private:

    int height, width, start_row, start_col;
    int timeout;

    void construct(int height, int width, int speed);

};

#endif 