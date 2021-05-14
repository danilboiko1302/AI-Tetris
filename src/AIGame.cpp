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

char AIGame::chooseShape() {
    minstd_rand simple_rand;
    simple_rand.seed(time(nullptr));
    simple_rand();
    simple_rand();
    simple_rand();


    int roll;
    int i;
    char piece;

    // Roll For piece
    for (roll = 0; roll < 6; ++roll) {
        i = simple_rand() % 35;
        piece = (*pool)[i];
        if (!history->contains(piece)) {
            break;
        }
    }

    while(true){
        char a = (*pieces)[simple_rand() % 7];
        if (!history->contains(a) ) {
            (*pool)[i] = a;
            break;
        }
    }
    history->cutFirst();
    //history.shift();
    history->add(piece);

    return piece;

}


bool AIGame::addShape() {
    if(simpleShapes)
        return Game::addShape();

    switch (chooseShape()) {
        case 'I':
            current = new I();
            break;
        case 'O':
            current = new O();
            break;
        case 'S':
            current = new S();
            break;
        case 'J':
            current = new J();
            break;
        case 'L':
            current = new L();
            break;
        case 'Z':
            current = new Z();
            break;
        case 'T':
            current = new T();
            break;
    }

    currentArr = &current->current;
    for (int i : *currentArr) {
        if (ar.at(i)) {
            return false;
        }
    }
    addShapeOnBoard();
    return true;
}

AIGame::~AIGame() {
    delete pieces;
    delete pool;
    delete history;

}

AIGame::AIGame(bool simple):simpleShapes(simple) {
    array<char, 7> shapes = {'I', 'J', 'L', 'O', 'S', 'T', 'Z'};

    pieces = new Sequence<char>;

    pool = new Sequence<char>;

    history = new Sequence<char>;


    for (char shape : shapes) {
        pieces->add(shape);
    }
    for (int i = 0; i < 5; ++i) {
        for (char shape : shapes) {
            pool->add(shape);
        }
    }
    history->add('S');
    history->add('Z');
    history->add('T');
    history->add('J');

}


