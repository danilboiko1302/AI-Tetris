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

    }

    virtual void play(){
        addShape();
        bool gameOver = false;
        while (!gameOver){
            seeBord();
            char b;
            cout  << "Choose move: " <<endl;
            cin >> b;
            cout  << b <<endl;
            switch(b){
                case  'd':
                    moveRight();
                    break;
                case  'a':
                    moveLeft();
                    break;
                case  's':
                    moveDown();
                    if(!addShape()){
                        gameOver = true;
                        cout<< "Your score = " << score << endl;
                        cout<< "You lose" << endl;
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


private:
    unsigned long long score = 0;
    static const unsigned int size = 10;
    Shape *current;
    array<int, 4> *currentArr;
    array<bool, (size * 10)> ar;
    void addShapeOnBoard(){
        for(int i : *currentArr){
            ar.at(i) = true;
        }
    }
    void turnShape(){
        removeShape();
        auto newShape = current->isTurnPossible();
        if(newShape == *currentArr){
            seeShape();
            return;
        }
        for(int i :  newShape){
            if(ar.at(i)){
                seeShape();
                return;
            }
        }
        for(int i = 0; i < 4; ++i)
            currentArr->at(i) = newShape.at(i);

        current->rotate();
        seeShape();

    }

    bool canMoveLeft(){
        for(int i : *currentArr)
            if(i%10 == 0)
                return false;

        array<int, 4> next = {};
        for(int i = 0; i < 4; ++i)
            next[i] = (*currentArr)[i] - 1;

        for(int i : next)
            if(ar.at(i))
                if (find(std::begin(*currentArr), end(*currentArr), i ) == end(*currentArr))
                    return false;
        return true;
    }
    bool canMoveRight(){
        for(int i : *currentArr)
            if(i%10 == 9)
                return false;

        array<int, 4> next = {};
        for(int i = 0; i < 4; ++i)
            next[i] = (*currentArr)[i] + 1;

        for(int i : next)
            if(ar.at(i))
                if (find(std::begin(*currentArr), end(*currentArr), i ) == end(*currentArr))
                    return false;
        return true;
    }
    void moveLeft(){
        if(canMoveLeft()){
            removeShape();
            current->moveLeft();
            seeShape();
        }

    }
    void moveDown(){
        bool canMove = true;
        while(canMove){
            canMove = checkMoveDown();
            if(canMove){
                removeShape();
                current->moveDown();
                seeShape();
            }
        }
        int *lines = new int(0);
        destroyLine(lines);
        score += (*lines);
    }

    void moveRight(){
        if(canMoveRight()) {
            removeShape();
            current->moveRight();
            seeShape();
        }
    }
    void destroyLine(int *lines){

        for(int i = 0; i < ar.size() / 10; ++i){
            bool line = true;
            for(int j = 0; j < 10; ++j){
                line = line && ar.at(i * 10 + j);
            }
            if(line){
                destroyLine(i);
                (*lines)++;
                destroyLine(lines);
                break;
            }
        }
    }
    void destroyLine(int line){

        for(int j = 0; j < 10; ++j){
            ar.at(line * 10 + j) = false;
        }
        for(int i = line - 1; i >= 0 ; --i){
            for(int j = 0; j < 10; ++j){
                ar.at((i + 1) * 10 + j) = ar.at(i * 10 + j);
            }
        }
    }

    bool checkMoveDown(){
        for (int i : *currentArr)
            if (find(std::begin(*currentArr), end(*currentArr), i + 10) == end(*currentArr)) {
                if (i + 10 >= size * 10 || ar.at(i + 10)) {
                    return false;
                }
            }
        return true;
    }
    void removeShape(){
        for(int i : *currentArr){
            ar.at(i) = false;
        }
    }
    void seeShape(){
        for(int i : *currentArr){
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
        cout << endl;
    }
    bool addShape(){
        std:: minstd_rand simple_rand;

        // Use simple_rand.seed() instead of srand():
        simple_rand.seed(time(0));

        // Use simple_rand() instead of rand():
        for (int i = 0; i < 10; ++i)
        {
            simple_rand();
        }
        switch (simple_rand()%7) {
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
        for(int i : *currentArr){
            if(ar.at(i)){
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
};


#endif //AI_TETRIS_GAME_H
