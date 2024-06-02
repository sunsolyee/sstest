#include <ncurses.h>
#include "Board.h"
#include "SnakeGame.h"
#include "Drawable.h"
#include <iostream>
#include <Time.h>

#define BOARD_DIM 30
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5


int main()
{
    initscr();
    refresh();

    noecho(); // �Է°��� screen�� ��µ��� �ʰ���
    // curs_set(0) ; // Ŀ���� ����

    // Board board(BOARD_ROWS, BOARD_COLS) ;
    // board.initialize() ;

    // board.addAt(5, 5, '#') ;
    // board.refresh() ; 

    SnakeGame game(BOARD_ROWS, BOARD_COLS, 200);

    // 4. game_over�� �ƴϸ� 1�� ���ư���
    while (!game.isOver())
    {
        // 1. ����ڿ��� �Է� �ޱ�
        game.processInput();

        // 2. ���� ���� ������Ʈ
        game.updateState();

        // 3. ���÷��̿� �ٽ� �׸���
        game.redraw();
    }

    // getch() ;
    endwin();

    std::cout << "You scored " << game.getScore() << " points!" << std::endl;

    return 0;
}