//
// Created by User on 5/6/2021.
//

#ifndef AI_TETRIS_GAME_H
#define AI_TETRIS_GAME_H

#include "Shape.h"
#include "Sequence.h"
#include<iostream>
#include <random>
#include <ctime>

using namespace std;

class Game {
public:
    Game();

    virtual void play();

    void turnShape();

    void moveLeft();

    void moveRight();

    void seeBoard();

    void addShapeOnBoard();


    bool canMoveLeft();

    bool canMoveRight();

    void moveDown();


    void destroyLine(int *lines);

    void destroyLine(int line);

    bool checkMoveDown();

    void removeShape();

    void seeShape();


    virtual bool addShape();


    static constexpr unsigned int size = 20;

    unsigned long score = 0;

    Shape *current{};
protected:

    array<bool, (size * 10)> ar;
    array<int, 4> *currentArr{};




};


#endif //AI_TETRIS_GAME_H
