//
// Created by User on 5/9/2021.
//

#ifndef AI_TETRIS_AI_H
#define AI_TETRIS_AI_H
#include "AIGame.h"
#include "Sequence.h"
#include <random>
using namespace std;
class AI {
public:
    AI():
    hole(50), height(50), moreThan3Holes(50), sonsAmount(50), step(50){};
    explicit AI(const  int son, const  int hole, const  int height, const  int moreThan3Holes, const  int step):
    hole(hole), height(height), moreThan3Holes(moreThan3Holes), sonsAmount(son), step(step){

    };

    AI& operator=(const AI& copy){
        if(this == &copy)
            return *this;
        hole = copy.hole;
        height = copy.height;
        moreThan3Holes = copy.moreThan3Holes;
        sonsAmount = copy.sonsAmount;
        step = copy.step;
        return *this;
    };
    void start(){
        createSons();
        sonsPlay();
    }

private:
     int sonsAmount;
     int hole;
     int height;
     int moreThan3Holes;
     int step;
     int score = 0;
     void sonsPlay(){
         for(size_t i = 0; i < sons->sizes(); ++i ){
             AIGame * game = new AIGame();
         }
     }
    void createSons(){
        minstd_rand simple_rand;
        simple_rand.seed(time(0));
        while(sons->sizes() != sonsAmount){
            int newHole = (hole + static_cast<int>(simple_rand()%(step + 1)) - static_cast<int>(step/2));
            int newHeight = height + static_cast<int>(simple_rand()%(step + 1)) - static_cast<int>(step/2);
            int newHoles = moreThan3Holes + static_cast<int>(simple_rand()%(step + 1)) - static_cast<int>(step/2);
            if(newHole < 0)
                newHole = 0;
            if(newHeight < 0)
                newHeight = 0;
            if(newHoles < 0)
                newHoles = 0;
            if(newHole > 100)
                newHole = 100;
            if(newHeight > 100)
                newHeight = 100;
            if(newHoles > 100)
                newHoles = 100;
            sons->add(AI(newHole,newHeight,newHoles));
        }




        for(size_t i = 0; i < sons->sizes(); ++i ){
            std::cout << i<< '\n';
            (*sons)[i].show();
        }
    }
    void show() const{
        cout<<"AI: " << sonsAmount << " "<< hole << " "<< height << " "<< moreThan3Holes << " "<< step << " " <<endl;
    }
    AI(const AI& copy):
            hole(copy.hole), height(copy.height), moreThan3Holes(copy.moreThan3Holes), sonsAmount(copy.sonsAmount), step(copy.step){
        sons = new Sequence<AI>(copy.sonsAmount);
        for(size_t i = 0; i < copy.sons->capacity(); ++i){
            (*sons)[i] = (*(copy.sons))[i];
        }
    };
    AI( const  int hole, const  int height, const  int moreThan3Holes):
            hole(hole), height(height), moreThan3Holes(moreThan3Holes), sonsAmount(0), step(0){

    };
    Sequence<AI> * sons = new Sequence<AI>;;

};


#endif //AI_TETRIS_AI_H
