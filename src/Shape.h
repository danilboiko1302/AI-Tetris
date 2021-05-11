//
// Created by Данило Бойко on 06.05.2021.
//

#ifndef AI_TETRIS_SHAPE_H
#define AI_TETRIS_SHAPE_H

#include<array>

using namespace std;

class Shape {
public:
    unsigned int state = 0;
    mutable array<int, 4> current;

    virtual array<int, 4> isTurnPossible() = 0;

    void moveLeft() const;

    void moveRight() const;

    void moveDown() const;

    void rotate();
};

class O : public Shape {
public:
    O();

    array<int, 4> isTurnPossible() override;

};

class I : public Shape {
public:
    I();

    array<int, 4> isTurnPossible() override;

};

class L : public Shape {
public:
    L();

    array<int, 4> isTurnPossible() override;
};

class J : public Shape {
public:
    J();

    array<int, 4> isTurnPossible() override;
};

class S : public Shape {
public:
    S();

    array<int, 4> isTurnPossible() override;
};

class Z : public Shape {
public:
    Z();

    array<int, 4> isTurnPossible() override;
};

class T : public Shape {
public:
    T();

    array<int, 4> isTurnPossible() override;
};


#endif //AI_TETRIS_SHAPE_H
