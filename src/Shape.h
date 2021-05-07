//
// Created by Данило Бойко on 06.05.2021.
//

#ifndef AI_TETRIS_SHAPE_H
#define AI_TETRIS_SHAPE_H
#include<array>
using namespace std;
class Shape {
public:
    unsigned char state = 0;
    mutable array<int, 4> current  ;
    virtual array<int, 4> isTurnPossible() = 0;
    void moveLeft() const {
        bool isPossible = true;
        for(int i : current){
            if(i%10 == 0){
                isPossible = false;
                break;
            }

        }
        if(isPossible){
            for(int & i : current){
                i--;
            }
        }
    };
    void moveRight() const{
        bool isPossible = true;
        for(int i : current){
            if(i%10 == 9){
                isPossible = false;
                break;
            }
        }
        if(isPossible){
            for(int & i : current){
                i++;
            }
        }
    };
    void moveDown() const{
        for(int & i : current){
            i+=10;
        }
    };

    void rotate() {
        state++;
    }
};

class O: public Shape {
public:
    O(){
        current = {4, 5, 14, 15};
    }
     array<int, 4> isTurnPossible () override{

         return current;
     };

};

class I: public Shape {
public:
    I(){
        current = {4, 14, 24, 34};
    }
    array<int, 4> isTurnPossible () override{
        array<int, 4> r{};
        switch (state%4) {
            case 0:
                r = {current.at(0) + 18,current.at(1) + 9, current.at(2), current.at(3) - 9 };
                break;
            case 1:
                r = {current.at(0) - 19,current.at(1) - 10, current.at(2) - 1, current.at(3) + 8 };
                break;
            case 2:
                r = {current.at(0) +9,current.at(1), current.at(2) - 9, current.at(3) - 18 };
                break;
            case 3:
                r = {current.at(0) - 8,current.at(1) + 1, current.at(2) + 10, current.at(3) + 19 };
                break;
            default:
                r = {};
                break;
        }
        return r;
    };

};

class L: public Shape {
public:
    L(){
        current = {5, 15, 14, 13};

    }
    array<int, 4> isTurnPossible () override{
        array<int, 4> r{};
        switch (state%4) {
            case 0:
                r = {current.at(0) + 20,current.at(1) + 9, current.at(2), current.at(3) - 9 };
                break;
            case 1:
                r = {current.at(0) - 2 ,current.at(1) - 11, current.at(2), current.at(3) + 11 };
                break;
            case 2:
                r = {current.at(0) - 20,current.at(1) - 9, current.at(2), current.at(3) + 9 };
                break;
            case 3:
                r = {current.at(0) + 2,current.at(1) + 11, current.at(2), current.at(3) - 11 };
                break;
            default:
                r = {};
                break;
        }
        return r;
    };
};

class J: public Shape {
public:
    J(){

        current = {3, 13, 14, 15};
    }
    array<int, 4> isTurnPossible () override{
        array<int, 4> r{};
        switch (state%4) {
            case 0:
                r = {current.at(0) + 2,current.at(1) - 9, current.at(2), current.at(3) + 9 };
                break;
            case 1:
                r = {current.at(0) + 20,current.at(1) + 11, current.at(2), current.at(3) - 11 };
                break;
            case 2:
                r = {current.at(0) - 2,current.at(1) + 9, current.at(2), current.at(3) - 9 };
                break;
            case 3:
                r = {current.at(0) - 20,current.at(1) - 11, current.at(2), current.at(3) + 11 };
                break;
            default:
                r = {};
                break;
        }
        return r;
    };
};

class S: public Shape {
public:
    S(){
        current = {5, 4, 14, 13};
    }
    array<int, 4> isTurnPossible () override{
        array<int, 4> r{};
        switch (state%4) {
            case 0:
                r = {current.at(0) + 20,current.at(1) + 11, current.at(2), current.at(3) - 9 };
                break;
            case 1:
                r = {current.at(0) - 2 ,current.at(1) + 9, current.at(2), current.at(3) + 11 };
                break;
            case 2:
                r = {current.at(0) - 20,current.at(1) - 11, current.at(2), current.at(3) + 9 };
                break;
            case 3:
                r = {current.at(0) + 2,current.at(1) - 9, current.at(2), current.at(3) - 11 };
                break;
            default:
                r = {};
                break;
        }
        return r;
    };
};
class Z: public Shape {
public:
    Z(){
        current = {4, 5, 15, 16};
    }
    array<int, 4> isTurnPossible () override{
        array<int, 4> r = {};
        switch (state%4) {
            case 0:
                r = {current.at(0) + 2,current.at(1) + 11, current.at(2), current.at(3) + 9 };
                break;
            case 1:
                r = {current.at(0) + 20,current.at(1) + 9, current.at(2), current.at(3) - 11 };
                break;
            case 2:
                r = {current.at(0) - 2,current.at(1) - 11, current.at(2), current.at(3) - 9 };
                break;
            case 3:
                r = {current.at(0) - 20,current.at(1) - 9, current.at(2), current.at(3) + 11 };
                break;
            default:
                r = {};
                break;
        }
        return r;
    };
};
class T: public Shape {
public:
    T(){
        current = {4, 13, 14, 15};
    }
    array<int, 4> isTurnPossible () override{
        array<int, 4> r = {};
        switch (state%4) {
            case 0:
                r = {current.at(0) + 11,current.at(1) - 9, current.at(2), current.at(3) + 9 };
                break;
            case 1:
                r = {current.at(0) + 9,current.at(1) + 11, current.at(2), current.at(3) - 11 };
                break;
            case 2:
                r = {current.at(0) - 11,current.at(1) + 9, current.at(2), current.at(3) - 9 };
                break;
            case 3:
                r = {current.at(0) - 9,current.at(1) - 11, current.at(2), current.at(3) + 11 };
                break;
            default:
                r = {};
                break;
        }
        return r;
    };
};


#endif //AI_TETRIS_SHAPE_H
