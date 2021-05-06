//
// Created by User on 5/6/2021.
//

#ifndef AI_TETRIS_GAME_H
#define AI_TETRIS_GAME_H
#include<array>
#include<iostream>
#include <random>
#include <ctime>
using namespace std;
class Game {
public:
    Game(): ar(){
        addShape();
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
    array<int, 4> *current{};
    array<bool,120> ar;
    void addShapeOnBoard(){
        for(int i : *current){
            ar.at(i) = true;
        }
    }
    bool addShape(){
        rand();
        rand();
        rand();
        switch (3) {
            case 0:
                current = new array<int, 4>{4, 5, 14, 15};
                addShapeOnBoard();
                break;
            case 1:
                current = new array<int, 4>{4, 14, 24, 34};
                addShapeOnBoard();
                break;
            case 2:
                current = new array<int, 4>{3, 13, 14, 15};
                addShapeOnBoard();
                break;
            case 3:
                current = new array<int, 4>{5, 13, 14, 15};
                addShapeOnBoard();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        };
    }
};


#endif //AI_TETRIS_GAME_H
