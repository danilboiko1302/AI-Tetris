//
// Created by User on 5/9/2021.
//

#ifndef AI_TETRIS_AI_H
#define AI_TETRIS_AI_H

#include "AIGame.h"
#include <fstream>
#include <random>

using namespace std;

class AI {
public:
    AI();

    explicit AI(int, int, int, int, int, int, bool);

    AI &operator=(const AI &);

    unsigned long start();

private:

    AI(const AI &);

    AI(int, int, int, int, bool);

    AI(int, int, int, int, int, int, bool, int);


    int sonsAmount;
    int hole;
    int height;
    int moreThan3Holes;
    int step;
    int destroy;
    int level;
    bool simpleShapes;
    unsigned long score = 0;

    unsigned long sonsPlay();

    static Sequence<array<bool, Game::size * 10>> &allBoards(Shape &, array<bool, Game::size * 10>);

    static bool checkBoard(array<int, 4>, array<bool, Game::size * 10>);

    static int width(array<int, 4>);

    static int heightShape(array<int, 4>);

    static int scoreBoard(array<bool, Game::size * 10>, int, int, int, int);

    static int countDestroy(array<bool, Game::size * 10>);

    static int countHoles(array<bool, Game::size * 10>);

    static int countHeight(array<bool, Game::size * 10>);

    static int countColumns(array<bool, Game::size * 10>);

    static void seeBoard(array<bool, Game::size * 10>);

    static bool turn(AIGame &);

    static void goToLeftSide(AIGame &);

    void createSons();

    void show() const;



    Sequence<AI> *sons = new Sequence<AI>;

};


#endif //AI_TETRIS_AI_H
