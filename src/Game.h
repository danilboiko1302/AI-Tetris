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
                    }
                    cout<< "You lose" << endl;
                    break;

            }
        }



    }
    void moveLeft(){
        removeShape();
        current->moveLeft();
        seeShape();
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
        destroyLine();
    }

    void moveRight(){
        removeShape();
        current->moveRight();
        seeShape();
    }
    void destroyLine(){
        for(int i = 0; i < ar.size() / 10; ++i){
            bool line = true;
            for(int j = 0; j < 10; ++j){
                line = line && ar.at(i * 10 + j);
            }
            if(line){
                destroyLine(i);
                destroyLine();
                break;
            }
        }
    }
    void destroyLine(int line){
        //TODO 
        for(int j = 0; j < 10; ++j){
            ar.at(line * 10 + j) = false;
        }
    }

    bool checkMoveDown(){
        bool isPossible = true;
        for(int i : *currentArr){
            if (find(std::begin(*currentArr), end(*currentArr), i + 10) == end(*currentArr)){

                if( i + 10 >= 120  || ar.at(i + 10) ){
                    isPossible = false;
                    break;
                }
            }

        }
        return isPossible;
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

private:
    Shape *current;
    array<int, 4> *currentArr;
    array<bool,120> ar;
    void addShapeOnBoard(){
        for(int i : *currentArr){
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
