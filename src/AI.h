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
    explicit AI(const unsigned int son, const unsigned int hole, const unsigned int height, const unsigned int moreThan3Holes, const unsigned int step):
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

    }

private:
    unsigned int sonsAmount;
    unsigned int hole;
    unsigned int height;
    unsigned int moreThan3Holes;
    unsigned int step;
    void createSons(){
        while(sons->sizes() != sonsAmount){
            minstd_rand simple_rand;
            simple_rand.seed(time(0));
            sons->add(AI(1,1,1,1));
        }



        for (int ii = 0; ii < 10; ++ii)
        {
            std::cout << simple_rand() << '\n';
        }
        for(size_t i = 0; i < sons->sizes(); ++i ){
            (*sons)[i].show();
        }
    }
    void show(){
        cout<<"AI: " << sonsAmount << " "<< hole << " "<< height << " "<< moreThan3Holes << " "<< step << " " <<endl;
    }
    AI(const AI& copy):
            hole(copy.hole), height(copy.height), moreThan3Holes(copy.moreThan3Holes), sonsAmount(copy.sonsAmount), step(copy.step){
        sons = new Sequence<AI>(copy.sonsAmount);
        for(size_t i = 0; i < copy.sons->capacity(); ++i){
            (*sons)[i] = (*(copy.sons))[i];
        }
    };
    AI(const unsigned int sons, const unsigned int hole, const unsigned int height, const unsigned int moreThan3Holes):
            hole(hole), height(height), moreThan3Holes(moreThan3Holes), sonsAmount(sons), step(0){

    };
    Sequence<AI> * sons = new Sequence<AI>;;

};


#endif //AI_TETRIS_AI_H
