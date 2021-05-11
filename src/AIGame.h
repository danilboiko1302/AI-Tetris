//
// Created by User on 5/9/2021.
//

#ifndef AI_TETRIS_AIGAME_H
#define AI_TETRIS_AIGAME_H

#include "Game.h"

class AIGame : public Game {
public:
    void play() override;

    array<bool, Game::size * 10> getBoard();

    array<int, 4> *getShape();

    Shape *getShapeClass();

    void setBoard(array<bool, Game::size * 10> newAr);

    void destroyLine();

    array<bool, Game::size * 10> nextMoveDown();

};


#endif //AI_TETRIS_AIGAME_H
