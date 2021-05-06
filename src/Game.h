//
// Created by User on 5/6/2021.
//

#ifndef AI_TETRIS_GAME_H
#define AI_TETRIS_GAME_H
#include "Shape.h"
#include<iostream>
#include <random>
#include <ctime>
using namespace std;
class Game {
public:
    Game(): ar(){
        addShape();
    }
    void moveLeft(){
        for(int i : *current->current){
            ar.at(i) = false;
        }
        current->moveLeft();
        for(int i : *current->current){
            ar.at(i) = true;
        }
    }
    void moveRight(){
        for(int i : *current->current){
            ar.at(i) = false;
        }
        current->moveRight();
        for(int i : *current->current){
            ar.at(i) = true;
        }
    }
    void seeBord(){
        for(int i = 0; i < ar.max_size(); ++i){
            if(i%10==0){
                cout<<endl;
            }
            cout<<ar.at(i);
        }
    }

private:
    Shape *current;
    array<bool,120> ar;
    void addShapeOnBoard(){
        for(int i : *current->current){
            ar.at(i) = true;
        }
    }
    bool addShape(){
        rand();
        rand();
        rand();
        switch (rand()%7) {
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
        };
        addShapeOnBoard();
    }
};


#endif //AI_TETRIS_GAME_H
