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

    noecho(); // 입력값이 screen에 출력되지 않게함
    // curs_set(0) ; // 커서를 삭제

    // Board board(BOARD_ROWS, BOARD_COLS) ;
    // board.initialize() ;

    // board.addAt(5, 5, '#') ;
    // board.refresh() ; 

    SnakeGame game(BOARD_ROWS, BOARD_COLS, 200);

    // 4. game_over가 아니면 1로 돌아가기
    while (!game.isOver())
    {
        // 1. 사용자에게 입력 받기
        game.processInput();

        // 2. 게임 상태 업데이트
        game.updateState();

        // 3. 디스플레이에 다시 그리기
        game.redraw();
    }

    // getch() ;
    endwin();

    std::cout << "You scored " << game.getScore() << " points!" << std::endl;

    return 0;
}