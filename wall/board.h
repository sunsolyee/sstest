#ifndef BOARD_H
#define BOARD_H

#include "Drawable.h"

class Board
{
public:
    Board();
    Board(int height, int width, int speed);
    void initialize(); // ������ �ʱ�ȭ
    void addBorder(); // �׵θ� ����
    void add(Drawable drawable); // Drawable ���� ���� ���
    void addAt(int y, int x, chtype ch); //�����쿡 ���� ���(�׵θ� ���� x, y�� ����)
    void getEmptyCoordinates(int& y, int& x);
    void getWallCoordinates(int& y, int& x);
    chtype getCharat(int y, int x);
    chtype getInput(); // ����� �Է� �ޱ�
    void clear(); //������ �����
    void refresh(); //������ ���̱�
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