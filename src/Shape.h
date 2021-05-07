//
// Created by Данило Бойко on 06.05.2021.
//

#ifndef AI_TETRIS_SHAPE_H
#define AI_TETRIS_SHAPE_H
#include<array>
using namespace std;
class Shape {
public:
    int state = 0;
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
};

class O: public Shape {
public:
    O(){
        current = {4, 5, 14, 15};
    }
      void turn() {
     };
     array<int, 4> isTurnPossible () override{
         array<int, 4> r = {};
         return r;
     };

};

class I: public Shape {
public:
    I(){
        current = {4, 14, 24, 34};
    }
    void turn() {
    };
    array<int, 4> isTurnPossible () override{
        array<int, 4> r = {};
        return r;
    };

};

class L: public Shape {
public:
    L(){
        current = {5, 13, 14, 15};
    }
    void turn() {
    };
    array<int, 4> isTurnPossible () override{
        array<int, 4> r = {};
        return r;
    };
};

class J: public Shape {
public:
    J(){
        current = {5, 13, 14, 15};
    }
    void turn() {
    };
    array<int, 4> isTurnPossible () override{
        array<int, 4> r = {};
        return r;
    };
};

class S: public Shape {
public:
    S(){
        current = {4, 5, 13, 14};
    }
    void turn() {
    };
    array<int, 4> isTurnPossible () override{
        array<int, 4> r = {};
        return r;
    };
};
class Z: public Shape {
public:
    Z(){
        current = {4, 5, 15, 16};
    }
    void turn() {
    };
    array<int, 4> isTurnPossible () override{
        array<int, 4> r = {};
        return r;
    };
};
class T: public Shape {
public:
    T(){
        current = {4, 13, 14, 15};
    }
    void turn() {
    };
    array<int, 4> isTurnPossible () override{
        array<int, 4> r = {};
        return r;
    };
};


#endif //AI_TETRIS_SHAPE_H
