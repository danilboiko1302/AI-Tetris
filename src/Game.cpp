//
// Created by User on 5/6/2021.
//

#include "Game.h"

Game::Game() : ar() {

}

void Game::play() {
    addShape();
    bool gameOver = false;
    while (!gameOver) {
        seeBoard();
        char b;
        cout << "Choose move: " << endl;
        cin >> b;
        cout << b << endl;
        switch (b) {
            case 'd':
                moveRight();
                break;
            case 'a':
                moveLeft();
                break;
            case 's':
                moveDown();
                if (!addShape()) {
                    gameOver = true;
                    cout << "Your score = " << score << endl;
                    cout << "You lose" << endl;
                }
                break;
            case 'w':
                turnShape();
                break;
            default:
                break;

        }
    }
}

void Game::turnShape() {
    removeShape();
    auto newShape = current->isTurnPossible();
    if (newShape == *currentArr) {
        seeShape();
        return;
    }
    for (int i :  newShape) {
        if (ar.at(i)) {
            seeShape();
            return;
        }
    }
    for (int i = 0; i < 4; ++i)
        currentArr->at(i) = newShape.at(i);

    current->rotate();
    seeShape();
}

void Game::moveLeft() {
    if (canMoveLeft()) {
        removeShape();
        current->moveLeft();
        seeShape();
    }

}

void Game::moveRight() {
    if (canMoveRight()) {
        removeShape();
        current->moveRight();
        seeShape();
    }
}

void Game::seeBoard() {
    for (int i = 0; i < ar.max_size(); ++i) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << ar.at(i);

    }
    cout << endl;
}

void Game::addShapeOnBoard() {
    for (int i : *currentArr) {
        ar.at(i) = true;
    }
}


bool Game::canMoveLeft() {
    for (int i : *currentArr)
        if (i % 10 == 0)
            return false;

    array<int, 4> next = {};
    for (int i = 0; i < 4; ++i)
        next[i] = (*currentArr)[i] - 1;

    for (int i : next)
        if (ar.at(i))
            if (find(std::begin(*currentArr), end(*currentArr), i) == end(*currentArr))
                return false;
    return true;
}

bool Game::canMoveRight() {
    for (int i : *currentArr)
        if (i % 10 == 9)
            return false;

    array<int, 4> next = {};
    for (int i = 0; i < 4; ++i)
        next[i] = (*currentArr)[i] + 1;

    for (int i : next)
        if (ar.at(i))
            if (find(std::begin(*currentArr), end(*currentArr), i) == end(*currentArr))
                return false;
    return true;
}

void Game::moveDown() {
    bool canMove = true;
    while (canMove) {
        canMove = checkMoveDown();
        if (canMove) {
            removeShape();
            current->moveDown();
            seeShape();
        }
    }
    int *lines = new int(0);
    destroyLine(lines);
    score += (*lines);
    delete lines;
}


void Game::destroyLine(int *lines) {

    for (int i = 0; i < ar.size() / 10; ++i) {
        bool line = true;
        for (int j = 0; j < 10; ++j) {
            line = line && ar.at(i * 10 + j);
        }
        if (line) {
            destroyLine(i);
            (*lines)++;
            destroyLine(lines);
            break;
        }
    }
}

void Game::destroyLine(int line) {

    for (int j = 0; j < 10; ++j) {
        ar.at(line * 10 + j) = false;
    }
    for (int i = line - 1; i >= 0; --i) {
        for (int j = 0; j < 10; ++j) {
            ar.at((i + 1) * 10 + j) = ar.at(i * 10 + j);
        }
    }
}

bool Game::checkMoveDown() {
    for (int i : *currentArr)
        if (find(std::begin(*currentArr), end(*currentArr), i + 10) == end(*currentArr)) {
            if (i + 10 >= size * 10 || ar.at(i + 10)) {
                return false;
            }
        }
    return true;
}

void Game::removeShape() {
    for (int i : *currentArr) {
        ar.at(i) = false;
    }
}

void Game::seeShape() {
    for (int i : *currentArr) {
        ar.at(i) = true;
    }
}




bool Game::addShape() {
    rand();
    rand();
    rand();
    rand();
    rand();
    delete current;
    switch (rand() % 7) {
        case 0:
            current = new O();
            break;
        case 1:
            current = new I();
            break;
        case 2:
            current = new L();
            break;
        case 3:
            current = new J();
            break;
        case 4:
            current = new S();
            break;
        case 5:
            current = new Z();
            break;
        case 6:
            current = new T();
            break;
    }

    currentArr = &current->current;
    for (int i : *currentArr) {
        if (ar.at(i)) {
            return false;
        }
    }

//        for(int i : current->current){
//            cout<< i << endl;
//        }
//        for(int i : *currentArr){
//            cout<< i << endl;
//        }
//        current->current.at(0) = 0;
//        for(int i : current->current){
//            cout<< i << endl;
//        }
//        for(int i : *currentArr){
//            cout<< i << endl;
//        }
    addShapeOnBoard();
    return true;
}