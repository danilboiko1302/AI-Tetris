//
// Created by User on 5/9/2021.
//

#include "AIGame.h"

void AIGame::play() {
    addShape();
}

array<bool, Game::size * 10> AIGame::getBoard() {
    return ar;
}

array<int, 4> *AIGame::getShape() {
    return currentArr;
}

Shape *AIGame::getShapeClass() {
    return current;
}

void AIGame::setBoard(array<bool, Game::size * 10> newAr) {
    ar = newAr;
}

void AIGame::destroyLine() {
    int *lines = new int(0);
    Game::destroyLine(lines);
    score += (*lines);
}

array<bool, Game::size * 10> AIGame::nextMoveDown() {
    auto prev = ar;
    bool canMove = true;
    while (canMove) {
        canMove = checkMoveDown();
        if (canMove) {
            removeShape();
            current->moveDown();
            seeShape();
        }
    }
    auto next = ar;
    ar = prev;
    delete &prev;
    return next;
}