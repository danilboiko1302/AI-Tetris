//
// Created by User on 5/9/2021.
//

#ifndef AI_TETRIS_AIGAME_H
#define AI_TETRIS_AIGAME_H

#include "Game.h"

class AIGame : public Game {
public:
    ~AIGame();

    explicit AIGame(bool);

    void play() override;

    array<bool, Game::size * 10> getBoard();

    array<int, 4> *getShape();

    Shape *getShapeClass();

    void setBoard(array<bool, Game::size * 10> newAr);

    void destroyLine();

    bool addShape() override;

    bool simpleShapes;

    array<bool, Game::size * 10> nextMoveDown();

    Sequence<char>* pieces;

    Sequence<char>* pool;

    Sequence<char>* history;

    char chooseShape();
};


#endif //AI_TETRIS_AIGAME_H
