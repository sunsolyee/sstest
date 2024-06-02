#include "SnakeGame.h"
#include "Board.h"
#include <iostream>
#include <Time.h>
#include "Growth.h"
#include "Empty.h"
#include "Snake.h"
#include "Wall.h"


void SnakeGame::handleNextPiece(snakePiece next)
{
    int toggle = 1;
    int toggle_g = 1;
    if (Growth != NULL || poison != NULL)
    {
        switch (board.getCharat(next.getY(), next.getX()))
        {
        case '@':
        {
            if (snake.getSize() == maxLength)
            {
                // cout << snake.getSize() << endl ;
                // cout << maxLength << endl ;
                int emptyRow = snake.tail().getY();
                int emptyCol = snake.tail().getX();
                board.add(Empty(emptyRow, emptyCol));
                snake.removePiece();
            }
            eatGrowth();
            break;
        }
        case '++':
        {
            int emptyRow = snake.tail().getY();
            int emptyCol = snake.tail().getX();
            board.add(Empty(emptyRow, emptyCol));
            snake.removePiece();
            eatSpeedup();
            break;
        }
        case '--':
        {
            int emptyRow = snake.tail().getY();
            int emptyCol = snake.tail().getX();
            board.add(Empty(emptyRow, emptyCol));
            snake.removePiece();
            eatSpeeddown();
            break;
        }
        case '!':
        {
            toggle = 0;
            int emptyRow = snake.tail().getY();
            int emptyCol = snake.tail().getX();
            board.add(Empty(emptyRow, emptyCol));
            snake.removePiece();
            eatPoison();
            break;
        }
        case 'ㅁ':
        {
            toggle_g = 0;

            gate[0]->toggle += snake.getSize() + 5;
            // int emptyRow = snake.tail().getY() ;
            // int emptyCol = snake.tail().getX() ;
            // board.add(Empty(emptyRow, emptyCol)) ;
            // snake.removePiece() ;

            int newRow, newCol;
            if (next.getY() == gate[0]->getY() && next.getX() == gate[0]->getX())
            {
                newRow = gate[1]->getY();
                newCol = gate[1]->getX();
                // cout << "i am gate[0]" << endl ;
            }
            else
            {
                newRow = gate[0]->getY();
                newCol = gate[0]->getX();
                // cout << "i am gate[1]" << endl ;
            }


            if (newRow == 1)
            {
                snake.setDirection(down);
                next = SnakePiece(++newRow, newCol);
            }
            else if (newRow == board.getHeight() - 2)
            {
                snake.setDirection(up);
                next = SnakePiece(--newRow, newCol);
            }
            else if (newCol == 1)
            {
                snake.setDirection(Direction::right);
                next = SnakePiece(newRow, ++newCol);
            }
            else if (newCol == board.getWidth() - 2)
            {
                snake.setDirection(Direction::left);
                next = SnakePiece(newRow, --newCol);
            }

            eatGate();

            // snake.addPiece(SnakePiece(newRow, newCol)) ;
            // board.add(SnakePiece(newRow, newCol)) ;


        }
        case ' ':
        {
            int emptyRow = snake.tail().getY();
            int emptyCol = snake.tail().getX();
            board.add(Empty(emptyRow, emptyCol));
            snake.removePiece();
            break;
        }
        default:
            game_over = true;
            break;
        }


    }
    // 사과에 안 닿았을 때
    // if(apple != NULL && (next.getX() != apple->getX() || next.getY() != apple->getY()))
    // {
    //     int emptyRow = snake.tail().getY() ;
    //     int emptyCol = snake.tail().getX() ;
    //     board.add(Empty(emptyRow, emptyCol)) ;
    //     snake.removePiece() ;
    // }
    // else
    // {
    //     eatApple() ;
    // }
    // if(toggle_g == 1)
    // {
    board.add(next);
    // Drawable draw(snake.head().getY(), snake.head().getX(), 'H') ;
    // board.add(draw) ;

    //body 부분을 head와 다르게 하기 위한 코드
    if (!snake.prev_pices.empty())
    {
        snake.prev_pices.back().icon = 'x';
        board.add(Empty(snake.prev_pices.back().getY(), snake.prev_pices.back().getX()));
        board.add(snake.prev_pices.back());
    }


    snake.addPiece(next);
    // }
    if (toggle == 0) {
        int emptyRow = snake.tail().getY();
        int emptyCol = snake.tail().getX();
        board.add(Empty(emptyRow, emptyCol));
        snake.removePiece();
    }

}

void SnakeGame::createGrowth()
{
    int y, x;
    board.getEmptyCoordinates(y, x);
    growth = new Growth(y, x);
    // board.add(Empty(growth->getY(), growth->getX())) ;
    board.add(*growth);
}

void SnakeGame::createPoison()
{
    int y, x;
    board.getEmptyCoordinates(y, x);
    poison = new Poison(y, x);
    board.add(*poison);
}

void SnakeGame::createSpeedup()
{
    int y, x;
    board.getEmptyCoordinates(y, x);
    speedup = new Speedup(y, x);
    board.add(*speedup);
}
void SnakeGame::createSpeeddown()
{
    int y, x;
    board.getEmptyCoordinates(y, x);
    speeddown = new Speeddown(y, x);
    board.add(*speeddown);
}

void SnakeGame::createGate()
{

    int y_0, x_0;
    board.getWallCoordinates(y_0, x_0);
    while (y_0 != 1 && x_0 != 1 && x_0 != board.getWidth() - 2 && y_0 != board.getHeight() - 2)
        board.getWallCoordinates(y_0, x_0);
    gate[0] = new Gate(y_0, x_0);
    board.add(*gate[0]);

    int y_1, x_1;
    board.getWallCoordinates(y_1, x_1);
    while (y_0 == y_1 || x_0 == x_1 || (y_1 != 1 && x_1 != 1 && x_1 != board.getWidth() - 2 && y_1 != board.getHeight() - 2))
        board.getWallCoordinates(y_1, x_1);
    gate[1] = new Gate(y_1, x_1);
    board.add(*gate[1]);



    // gate[0] = new Gate(3, 20) ;
    // board.add(*(gate[0]));
    // gate[0] = new Gate(3, 30) ;
    // board.add(*(gate[1]));
}

void SnakeGame::createWall(int y, int x)
{
    Wall wall(y, x);
    board.add(wall);
}

void SnakeGame::createImmWall(int y, int x)
{
    Immwall immWall(y, x);
    board.add(immWall);
}

void SnakeGame::createMap()
{
    createImmWall(1, 1); createImmWall(1, board.getWidth() - 2);
    createImmWall(board.getHeight() - 2, 1); createImmWall(board.getHeight() - 2, board.getWidth() - 2);

    for (int i = 2; i < board.getWidth() - 2; i++)
        createWall(1, i);
    for (int i = 2; i < board.getHeight() - 2; i++)
        createWall(i, 1);
    for (int i = 2; i < board.getWidth() - 2; i++)
        createWall(board.getHeight() - 2, i);
    for (int i = 2; i < board.getHeight() - 2; i++)
        createWall(i, board.getWidth() - 2);

    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i);
    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i + 10);
    // for(int i = board.getHeight() - 25 ; i < board.getHeight()-10 ; i++)
    //     createWall(i, i+20) ;
    // for(int i = board.getHeight() - 25 ; i < board.getHeight()-10 ; i++)
    //     createWall(i, i+30) ;
    // for(int i = board.getHeight() - 25 ; i < board.getHeight()-10 ; i++)
    //     createWall(i, i+40) ;
    // for(int i = board.getHeight() - 25 ; i < board.getHeight()-10 ; i++)
    //     createWall(i, i+50) ;



}

void SnakeGame::createMap2()
{
    createImmWall(1, 1); createImmWall(1, board.getWidth() - 2);
    createImmWall(board.getHeight() - 2, 1); createImmWall(board.getHeight() - 2, board.getWidth() - 2);

    for (int i = 2; i < board.getWidth() - 2; i++)
        createWall(1, i);
    for (int i = 2; i < board.getHeight() - 2; i++)
        createWall(i, 1);
    for (int i = 2; i < board.getWidth() - 2; i++)
        createWall(board.getHeight() - 2, i);
    for (int i = 2; i < board.getHeight() - 2; i++)
        createWall(i, board.getWidth() - 2);

    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i);
    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i + 10);
    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i + 20);
    // for(int i = board.getHeight() - 25 ; i < board.getHeight()-10 ; i++)
    //     createWall(i, i+30) ;
    // for(int i = board.getHeight() - 25 ; i < board.getHeight()-10 ; i++)
    //     createWall(i, i+40) ;
    // for(int i = board.getHeight() - 25 ; i < board.getHeight()-10 ; i++)
    //     createWall(i, i+50) ;



}

void SnakeGame::createMap3()
{
    createImmWall(1, 1); createImmWall(1, board.getWidth() - 2);
    createImmWall(board.getHeight() - 2, 1); createImmWall(board.getHeight() - 2, board.getWidth() - 2);

    for (int i = 2; i < board.getWidth() - 2; i++)
        createWall(1, i);
    for (int i = 2; i < board.getHeight() - 2; i++)
        createWall(i, 1);
    for (int i = 2; i < board.getWidth() - 2; i++)
        createWall(board.getHeight() - 2, i);
    for (int i = 2; i < board.getHeight() - 2; i++)
        createWall(i, board.getWidth() - 2);

    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i);
    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i + 10);
    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i + 20);
    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i + 30);
    // for(int i = board.getHeight() - 25 ; i < board.getHeight()-10 ; i++)
    //     createWall(i, i+40) ;
    // for(int i = board.getHeight() - 25 ; i < board.getHeight()-10 ; i++)
    //     createWall(i, i+50) ;



}


void SnakeGame::createMap4()
{
    createImmWall(1, 1); createImmWall(1, board.getWidth() - 2);
    createImmWall(board.getHeight() - 2, 1); createImmWall(board.getHeight() - 2, board.getWidth() - 2);

    for (int i = 2; i < board.getWidth() - 2; i++)
        createWall(1, i);
    for (int i = 2; i < board.getHeight() - 2; i++)
        createWall(i, 1);
    for (int i = 2; i < board.getWidth() - 2; i++)
        createWall(board.getHeight() - 2, i);
    for (int i = 2; i < board.getHeight() - 2; i++)
        createWall(i, board.getWidth() - 2);

    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i);
    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i + 10);
    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i + 20);
    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i + 30);
    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i + 40);
    for (int i = board.getHeight() - 25; i < board.getHeight() - 10; i++)
        createWall(i, i + 50);



}

void SnakeGame::eatGrowth()
{
    delete growth;
    growth = NULL;
    score += 100;
    growth_item++;
    length++;
    // scoreboard.updateScore(score) ;
    scoreboard.updateLength(length);
    scoreboard.updateGrowth(growth_item);
    scoreboard.updatePoison(poison_item);
    scoreboard.updateGate(gate_item);
    scoreboard.updateTime(time(NULL) - time_s);
    scoreboard.updateSpeedup(view_speed);
}

void SnakeGame::eatPoison()
{
    delete poison;
    poison = NULL;
    score -= 100;
    poison_item++;
    length--;
    // scoreboard.updateScore(score) ;
    scoreboard.updateLength(length);
    scoreboard.updateGrowth(growth_item);
    scoreboard.updatePoison(poison_item);
    scoreboard.updateGate(gate_item);
    scoreboard.updateTime(time(NULL) - time_s);
    scoreboard.updateSpeedup(view_speed);
}

void SnakeGame::eatSpeedup()
{
    speedup_n -= 10;
    view_speed += 10;
    wtimeout(board.board_win, speedup_n);
    // scoreboard.updateScore(score) ;
    scoreboard.updateLength(length);
    scoreboard.updateGrowth(growth_item);
    scoreboard.updatePoison(poison_item);
    scoreboard.updateGate(gate_item);
    scoreboard.updateTime(time(NULL) - time_s);
    scoreboard.updateSpeedup(view_speed);
}
void SnakeGame::eatSpeeddown()
{
    speedup_n += 10;
    view_speed -= 10;
    wtimeout(board.board_win, speedup_n);
    // scoreboard.updateScore(score) ;
    scoreboard.updateLength(length);
    scoreboard.updateGrowth(growth_item);
    scoreboard.updatePoison(poison_item);
    scoreboard.updateGate(gate_item);
    scoreboard.updateTime(time(NULL) - time_s);
    scoreboard.updateSpeedup(view_speed);
}

void SnakeGame::eatGate()
{
    gate_item++;
    // scoreboard.updateScore(score) ;
    scoreboard.updateLength(length);
    scoreboard.updateGrowth(growth_item);
    scoreboard.updatePoison(poison_item);
    scoreboard.updateGate(gate_item);
    scoreboard.updateTime(time(NULL) - time_s);
    scoreboard.updateSpeedup(view_speed);
}

void SnakeGame::eatTime()
{
    int time_e = time(NULL) - time_s;
    // scoreboard.updateScore(score) ;
    scoreboard.updateLength(length);
    scoreboard.updateGrowth(growth_item);
    scoreboard.updatePoison(poison_item);
    scoreboard.updateGate(gate_item);
    scoreboard.updateTime(time(NULL) - time_s);
    scoreboard.updateSpeedup(view_speed);
}

SnakeGame::SnakeGame(int height, int width, int speed)
{
    board = Board(height, width, speed);
    int sb_row = board.getStartRow() + height;
    int sb_col = board.getStartCol();
    scoreboard = Scoreboard(width, sb_row, sb_col);
    missionboard = MissionBoard(width, sb_row, sb_col + width / 2);
    mission = Mission();
    time_s = time(NULL);
    initialize();

}

SnakeGame::~SnakeGame()
{
    delete growth;
    delete poison;
}

void SnakeGame::initialize()
{
    stage = 0;
    apple = NULL;
    poison = NULL;
    gate[0] = NULL;
    gate[1] = NULL;
    speedup = NULL;
    speeddown = NULL;
    gate_c = 70;
    board.initialize(); // board 초기화
    score = 0;
    length = 3;
    growth_item = 0;
    poison_item = 0;
    gate_item = 0;
    maxLength = 6;
    speedup_n = 200;
    view_speed = 200;
    new_wall = 30;
    int time_e = time_s - time(NULL);
    scoreboard.initialize(score, length, poison_item, growth_item, gate_item, time_e, speedup_n);
    char initial_length, initial_growth, initial_poison, initial_gate, initial_speed;
    initial_length = initial_growth = initial_poison = initial_gate = initial_speed = 'X';
    missionboard.initialize(initial_length, initial_growth, initial_poison, initial_gate, initial_speed);
    game_over = false; // 게임 상태 초기화
    srand(time(NULL)); // random 잘 나오게 초기화

    createMap();

    snake.setDirection(Direction::down);

    //4의 조각을 가진 뱀 생성
    handleNextPiece(SnakePiece(2, 2));
    handleNextPiece(snake.nextHead());
    handleNextPiece(snake.nextHead());

    snake.setDirection(Direction::right);


    if (growth == NULL) // apple 없으면 빈 공간에 생성
    {
        createGrowth();
    }
    if (poison == NULL) // apple 없으면 빈 공간에 생성
    {
        createPoison();
    }
    if (speedup == NULL)
    {
        createSpeedup();
    }
    if (speeddown == NULL)
    {
        createSpeeddown();
    }

}

void SnakeGame::processInput()
{
    chtype input = board.getInput();

    int old_timeout = board.getTimeout();
    switch (input)
    {
    case KEY_UP:
    case 'w':
        if (snake.setDirection(up) == 1) game_over = true;
        break;
    case KEY_DOWN:
    case 's':
        if (snake.setDirection(down) == 1) game_over = true;
        break;
    case KEY_RIGHT:
    case 'd':
        if (snake.setDirection(Direction::right) == 1) game_over = true;
        break;
    case KEY_LEFT:
    case 'a':
        if (snake.setDirection(Direction::left) == 1) game_over = true;
        break;
    case 'p':
        board.setTimeout(-1); //기다리는 시간 무한
        while (board.getInput() != 'p')
            break;
        board.setTimeout(old_timeout);
    }
}

void SnakeGame::updateState()
{
    // cout <<snake.getSize() << endl ;
    if (snake.getSize() <= 2)
        game_over = true;
    // int y, x ;

    // board.getEmptyCoordinates(y, x) ;
    // board.add(Apple(y, x)) ;

    handleNextPiece(snake.nextHead());
    // 사과를 안 먹었을 때 처리

    if (growth != NULL)
        growth->toggle++;

    if (growth != NULL && growth->toggle == growth->r)
    {
        // apple->r = rand() % 40 + 30 ;
        growth->toggle = 0;
        board.add(Empty(growth->getY(), growth->getX()));
        int y, x;
        board.getEmptyCoordinates(y, x);
        growth->setYX(y, x);
        board.add(*growth);
    }

    if (speedup != NULL)
        speedup->toggle++;

    if (speedup != NULL && speedup->toggle == speedup->r)
    {
        // speed->r = rand() % 40 + 30 ;
        speedup->toggle = 0;
        board.add(Empty(speedup->getY(), speedup->getX()));
        int y, x;
        board.getEmptyCoordinates(y, x);
        speedup->setYX(y, x);
        board.add(*speedup);
    }

    if (poison != NULL)
        poison->toggle++;

    if (poison != NULL && poison->toggle == poison->r)
    {
        // poison->r = rand() % 40 + 30 ;
        poison->toggle = 0;
        board.add(Empty(poison->getY(), poison->getX()));
        int y, x;
        board.getEmptyCoordinates(y, x);
        poison->setYX(y, x);
        board.add(*poison);
    }

    if (growth == NULL) // apple 없으면 빈 공간에 생성
    {
        createGrowth();
    }
    if (poison == NULL)
    {
        createPoison();
    }

    if (gate[0] == NULL)
    {
        gate_c--;
    }

    if (gate[0] != NULL)
        gate[0]->toggle++;

    if (gate[0] != NULL && gate[0]->toggle == gate[0]->r)
    {

        gate[0]->toggle = 0;
        board.add(Wall(gate[0]->getY(), gate[0]->getX()));
        int y_0, x_0;
        board.getWallCoordinates(y_0, x_0);
        while (y_0 != 1 && x_0 != 1 && x_0 != board.getWidth() - 2 && y_0 != board.getHeight() - 2)
            board.getWallCoordinates(y_0, x_0);
        gate[0]->setYX(y_0, x_0);
        board.add(*gate[0]);

        board.add(Wall(gate[1]->getY(), gate[1]->getX()));
        int y_1, x_1;
        board.getWallCoordinates(y_1, x_1);
        while (y_0 == y_1 || x_0 == x_1 || (y_1 != 1 && x_1 != 1 && x_1 != board.getWidth() - 2 && y_1 != board.getHeight() - 2))
            board.getWallCoordinates(y_1, x_1);
        gate[1]->setYX(y_1, x_1);
        board.add(*gate[1]);
    }

    new_wall--;

    if (new_wall == 0)
    {
        new_wall = 30;
        int m, n;
        board.getEmptyCoordinates(m, n);
        board.add(Wall(m, n));
    }


    if (gate[0] == NULL && gate_c == 0)
    {
        gate_c = 70;
        createGate();
    }

    if (mission.clearGrowthMission(growth_item))
    {
        missionboard.updateGrowth('O');
        // cout << endl << " 되냐" << endl ;
    }
    if (mission.clearLengthMission(length))
    {
        missionboard.updateLength('O');
        // cout << endl << " 안되냐" << endl ;
    }
    if (mission.clearPoisonMission(poison_item))
    {
        missionboard.updatePoison('O');
        // cout << endl << " 되냐" << endl ;
    }
    if (mission.clearGateMission(gate_item))
    {
        missionboard.updateGate('O');
        // cout << endl << " 안되냐" << endl ;
    }
    if (mission.clearSpeedMission(view_speed))
    {
        missionboard.updateSpeed('O');
    }

    // if(mission.clearAppleMission(apple_item))
    if (mission.clearGateMission(gate_item) && mission.clearPoisonMission(poison_item) && mission.clearLengthMission(length) && mission.clearGrowthMission(growth_item) && mission.clearSpeedMission(view_speed))
    {
        // std::cout << std::endl << "whyrano" << std::endl ;

        stage++;
        growth = NULL;
        poison = NULL;
        gate[0] = NULL;
        gate[1] = NULL;
        gate_c = 70;
        board.initialize(); // board 초기화
        score = 0;
        length = 3;
        growth_item = 0;
        poison_item = 0;
        gate_item = 0;
        maxLength = 6;
        speedup_n = 200;
        view_speed = 200;
        int time_e = time_s - time(NULL);
        scoreboard.initialize(score, length, poison_item, growth_item, gate_item, time_e, speedup_n);
        char initial_length, initial_growth, initial_poison, initial_gate, initial_speedup;
        initial_length = initial_growth = initial_poison = initial_gate = initial_speedup = 'X';
        missionboard.initialize(initial_length, initial_growth, initial_poison, initial_gate, initial_speedup);

        if (stage == 1)

            createMap2();
        else if (stage == 2)
            createMap3();
        else if (stage == 3)
            createMap4();
        else if (stage == 4)
        {
            wtimeout(stdscr, -1);
            board.initialize(); // board 초기화
            wprintw(stdscr, "YOU WIN", board.getStartCol() + 5, board.getStartRow() + 5);
            getch();
            game_over = true;
        }

        if (growth == NULL) // apple 없으면 빈 공간에 생성
        {
            createGrowth();
        }
        if (poison == NULL) // apple 없으면 빈 공간에 생성
        {
            createPoison();
        }



    }

    // delete apple ;


    // board.add(Drawable(3, 3, '#')) ;
    // board.add(Drawable(3, 5, '@')) ;
    eatTime();
}

void SnakeGame::redraw()
{
    board.refresh();
    scoreboard.refresh();
    missionboard.refresh();
}

bool SnakeGame::isOver()
{
    return game_over;
}

int SnakeGame::getScore()
{
    return score;
}