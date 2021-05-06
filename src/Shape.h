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
    array<int, 4> *current;
    virtual array<int, 4> isTurnPossible() = 0;
    void moveLeft() const {
        bool isPossible = true;
        for(int i = 0; i < current->size(); ++i){
            if(current->at(i)%10 == 0){
                isPossible = false;
                break;
            }

        }
        if(isPossible){
            for(int i = 0; i < current->size(); ++i){
                current->at(i)--;
            }
        }
    };
    void moveRight() const{
        bool isPossible = true;
        for(int i = 0; i < current->size(); ++i){
            if(current->at(i)%10 == 9){
                isPossible = false;
                break;
            }
        }
        if(isPossible){
            for(int i = 0; i < current->size(); ++i){
                current->at(i)++;
            }
        }
    };
};

class O: public Shape {
public:
    O(){
        current = new array<int, 4>{4, 5, 14, 15};
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
        current = new array<int, 4>{4, 14, 24, 34};
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
        current = new array<int, 4>{5, 13, 14, 15};
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
        current = new array<int, 4>{5, 13, 14, 15};
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
        current = new array<int, 4>{4, 5, 13, 14};
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
        current = new array<int, 4>{4, 5, 15, 16};
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
        current = new array<int, 4>{4, 13, 14, 15};
    }
    void turn() {
    };
    array<int, 4> isTurnPossible () override{
        array<int, 4> r = {};
        return r;
    };
};


#endif //AI_TETRIS_SHAPE_H
