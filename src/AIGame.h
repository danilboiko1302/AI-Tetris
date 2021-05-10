//
// Created by User on 5/9/2021.
//

#ifndef AI_TETRIS_AIGAME_H
#define AI_TETRIS_AIGAME_H
#include "Game.h"

class AIGame : public Game{
public:
    void play() override{
        addShape();
    }
    auto getBoard(){
        return ar;
    }
    auto getShape(){
        return currentArr;
    }
    auto nextMoveDown(){
        auto prev = ar;
        bool canMove = true;
        while(canMove){
            canMove = checkMoveDown();
            if(canMove){
                removeShape();
                current->moveDown();
                seeShape();
            }
        }
        auto next = ar;
        ar = prev;
        return next;
    }

};




#endif //AI_TETRIS_AIGAME_H
