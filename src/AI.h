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
    AI() :
            hole(50), height(50), moreThan3Holes(50), sonsAmount(50), destroy(50), step(50) {};

    explicit AI(const int son, const int hole, const int height, const int moreThan3Holes, const int destroy, const int step) :
            hole(hole), height(height), moreThan3Holes(moreThan3Holes), sonsAmount(son), destroy(destroy),step(step) {

    };

    AI &operator=(const AI &copy) {
        if (this == &copy)
            return *this;
        hole = copy.hole;
        height = copy.height;
        moreThan3Holes = copy.moreThan3Holes;
        sonsAmount = copy.sonsAmount;
        destroy = copy.destroy;
        step = copy.step;
        return *this;
    };

    unsigned long long start() {
        createSons();
        return sonsPlay();
    }

private:
    int sonsAmount;
    int hole;
    int height;
    int moreThan3Holes;
    int step;
    int destroy;
    int score = 0;

    unsigned long long sonsPlay() {
        unsigned long long max = 0;
        int newHole = 0;
        int newHeight = 0;
        int newColumns = 0;
        int newDest = 0;
        for (size_t i = 0; i < sons->sizes(); ++i) {
            auto *game = new AIGame();
            game->play();
            while(true){

//                auto *positions = new Sequence<array<int, 4>>;
//
//                goToLeftSide(*game);
//
//                array<int, 4> board{};
//                array<int, 4> newBoard{};
//                do {
//                    positions->add(*(game->getShape()));
//                    //game->seeBoard();
//                    board = *(game->getShape());
//                    game->moveRight();
//                    newBoard = *(game->getShape());
//                } while (board != newBoard);
//
//                for (int j = 0; j < 3; ++j) {
//
//                    //game->seeBoard();
//                    if (turn(*game)) {
//                        //game->seeBoard();
//                        do {
//                            if (!positions->contains(*(game->getShape())))
//                                positions->add(*(game->getShape()));
//                            board = *(game->getShape());
//                            game->moveRight();
//                            newBoard = *(game->getShape());
//                        } while (board != newBoard);
//                    } else {
//                        break;
//                    }
//
//                }
//                game->removeShape();
//                auto *positionsBoard = new Sequence<array<bool, Game::size * 10>>;
//
//
//                for (int j = 0; j < positions->sizes(); ++j) {
//                    if (j != 0) {
//                        *game->getShape() = (*positions)[j - 1];
//                    }
//                    game->removeShape();
//                    *game->getShape() = (*positions)[j];
//                    game->seeShape();
//                    positionsBoard->add(game->nextMoveDown());
//                    //game->seeBoard();
//                }
//
////             for(int j =0; j<positionsBoard->sizes(); ++j ){
////                 seeBoard((*positionsBoard)[j]);
////             }
//                *game->getShape() = (*positions)[positions->sizes() - 1];
//                game->removeShape();



//             for(int j =0; j<positions->sizes(); ++j ){
//                 for(int k = 0; k < (*positions)[j].max_size(); ++k)
//                     cout<<(*positions)[j].at(k) << endl;
//                 cout << endl;
//             }

                auto *positionsBoard = &allBoards(*(game->getShapeClass()), (game->getBoard()));
                for(int j =0; j<positionsBoard->sizes(); ++j ){
                  //  seeBoard((*positionsBoard)[j]);
                }
                auto *scores = new Sequence<int>;
                //game->seeBoard();
                for(int j =0; j<positionsBoard->sizes(); ++j ){
                    scores->add(scoreBoard((*positionsBoard)[j], (*sons)[i].hole, (*sons)[i].height, (*sons)[i].moreThan3Holes, (*sons)[i].destroy));
                }
                int min = (*scores)[0];
                for(int j = 1; j<scores->sizes(); ++j ){
                    if((*scores)[j] < min){
                        min = (*scores)[j];
                    }
                    //cout<< (*scores)[j] << endl;
                }
               // cout<< min<< endl;

                //cout<< min << endl;
                // game->seeBoard();

                for(int j = 0; j<scores->sizes(); ++j ){
                    if((*scores)[j] == min){
                        game->setBoard((*positionsBoard)[j]);
                        break;
                    }
                    //cout<< (*scores)[j] << endl;
                }
            //    game->seeBoard();
                game->destroyLine();

                if(game->addShape()){
                    game->seeShape();
                  //  game->seeBoard();
                } else{
//                    cout<<"Height is " << (*sons)[i].height<< endl;
//                    cout<<"hole is " << (*sons)[i].hole<< endl;
//                    cout<<"moreThan3Holes is " << (*sons)[i].moreThan3Holes<< endl;
//                    cout<<"destroy is " << (*sons)[i].destroy<< endl;
//                    cout<<"Score is " << game->score<< endl;
//                    cout<< endl;
//                    cout<< endl;
                    if(game->score > max){
                        max = game->score;
                        newHole = (*sons)[i].hole;
                        newHeight = (*sons)[i].height;
                        newColumns = (*sons)[i].moreThan3Holes;
                        newDest = (*sons)[i].destroy;
                    }
                    break;
                }
            }




        }
        cout<<"MAX Score is " << max<< endl;
        return max;

        AI *next = new AI(this->sonsAmount, newHole, newHeight, newColumns, newDest, this->step);
        return next->start();

    }
    static Sequence<array<bool, Game::size * 10>> &allBoards(Shape& shape, array<bool, Game::size * 10> board) {
        auto * test = new Sequence<array<bool, Game::size * 10>>;
        for(int i :  shape.current){
            board.at(i) = false;
        }
        array<array<int, 4>, 4> shapes{};
        shapes.at(0) =  shape.current;
        shapes.at(1) =  shape.isTurnPossible();
        shape.current = shape.isTurnPossible();
        shape.rotate();
        shapes.at(2) =  shape.isTurnPossible();
        shape.current = shape.isTurnPossible();
        shape.rotate();
        shapes.at(3) =  shape.isTurnPossible();

      for(array<int, 4> tempShape : shapes){
          int maxWidth = 0;
          int maxHeight = 0;
          for(int i :  tempShape){
              if(i%10 > maxWidth)
                  maxWidth = i%10;
              if(i/10 > maxHeight)
                  maxHeight = i/10;
          }
          int max = maxHeight * 10 + maxWidth;
          int widthI = width(tempShape);
          int heightI = heightShape(tempShape);
          int start = Game::size - 1;
          for(int j = 9; j >=widthI - 1 ; --j){// line
              for(int i = start; i >=heightI - 1; --i){ //column
                  auto temp = board;
                  int move = i*10+j - max;
                  bool suc = true;
                  for(int k :  tempShape){
                      if(temp.at(k+move)){
                          suc = false;
                          break;
                      }
                  }
                  if(suc){
                      for(int k :  tempShape){
                          temp.at(k+move) = true;
                      }
                      array<int, 4> newShape{};
                      for(int k = 0 ; k < tempShape.size(); ++k)
                          newShape.at(k) = (tempShape.at(k) + move);

                      if(checkBoard(newShape, temp)){
                          if(!test->contains(temp)){
                              test->add(temp);
                          }

                          break;
                      }
                  }
              }
          }
      }


        return *test;
    }
    static bool checkBoard(array<int,4> shape, array<bool, Game::size * 10> board){

        for(int k :  shape){
            if(k+10 > board.size()){
                return true;
            } else{
                if (find(std::begin(shape), end(shape), k+10) != end(shape)){
                    if(board.at(k+10)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
    static int width(array<int, 4> shape) {
        int min  = 9;
        int max  = 0;
        for(int i :  shape){
            if(i%10 > max)
                max = i%10;
            if(i%10 < min)
                min = i%10;
        }
        return max-min+1;
    }
    static int heightShape(array<int, 4> shape) {
        int min  = 9;
        int max  = 0;
        for(int i :  shape){
            if(i/10 > max)
                max = i/10;
            if(i/10 < min)
                min = i/10;
        }
        return max-min+1;
    }

    static int scoreBoard(array<bool, Game::size * 10> ar, int hole, int height, int more3, int dest) {
        int res = countHoles(ar) * hole + countHeight(ar) * height + countColumns(ar) * more3 - countDestroy(ar) * dest;


        return res;
    }
    static int countDestroy(array<bool, Game::size * 10> ar){
        int res = 0;
        for (int i = 0; i < ar.size() / 10; ++i){
            bool line = true;
            for (int j = 0; j <  10; ++j){
                line = line && ar.at(i * 10 + j);
            }
            if(line){
                res++;
                //seeBoard(ar);
            }

        }
        return res;
    }

    static int countHoles(array<bool, Game::size * 10> ar) {
        int holes = 0;
        for (int i = 0; i < 10; ++i) {
            bool closed = false;
            for (int j = 0; j < ar.size() / 10; ++j)
                if (closed) {
                    if (!ar[i + j * 10])
                        holes++;

                } else {
                    if (ar[i + j * 10])
                        closed = true;
                }
        }
        return holes;
    }

    static int countHeight(array<bool, Game::size * 10> ar) {
        for (int i = 0; i < ar.size(); ++i)
            if (ar[i]) {
                return int(Game::size) - i / 10;
            }

        return 0;
    }

    static int countColumns(array<bool, Game::size * 10> ar) {
        int col = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = i; j < ar.size(); j += 10) {
                if (ar[j]) {
                    break;
                }
                if (i == 0) {
                    if (ar.at(j + 1)) {
                        if (int(Game::size) - j / 10 > 3) {
                            col += int(Game::size) - j / 10 - 3;
                        }
                    }
                } else if (i == 9) {
                    if (ar.at(j - 1)) {
                        if (int(Game::size) - j / 10 > 3) {
                            col += int(Game::size) - j / 10 - 3;
                        }
                    }
                } else {
                    if (ar.at(j - 1) && ar.at(j + 1)) {
                        if (int(Game::size) - j / 10 > 3) {
                            col += int(Game::size) - j / 10 - 3;
                        }
                        //cout<< Game::size  - j / 10<<endl;
                    }
                }
                //cout<<j<<endl;
            }
        }
        return col;
    }

    static void seeBoard(array<bool, Game::size * 10> ar) {
        for (int i = 0; i < ar.max_size(); ++i) {
            if (i % 10 == 0) {
                cout << endl;
            }
            cout << ar.at(i);

        }
        cout << endl;
    }

    static bool turn(AIGame &game) {
        goToLeftSide(game);
        auto startPos = *game.getShape();
        auto nextPos = *game.getShape();
        do {
            game.turnShape();
            nextPos = *game.getShape();
            if (startPos == nextPos) {
                game.moveRight();
                nextPos = *game.getShape();
                if (startPos == nextPos) {
                    return false;
                } else {
                    startPos = *game.getShape();
                }
            } else {
                goToLeftSide(game);
                return true;
            }

        } while (true);
    }

    static void goToLeftSide(AIGame &game) {
        array<bool, Game::size * 10> board{};
        array<bool, Game::size * 10> newBoard{};

        do {
            board = game.getBoard();
            game.moveLeft();
            newBoard = game.getBoard();
        } while (board != newBoard);
    }

    void createSons() {
        minstd_rand simple_rand;
        simple_rand.seed(time(0));
        while (sons->sizes() != sonsAmount) {
            int newHole = (hole + static_cast<int>(simple_rand() % (step + 1)) - static_cast<int>(step / 2));
            int newHeight = height + static_cast<int>(simple_rand() % (step + 1)) - static_cast<int>(step / 2);
            int newHoles = moreThan3Holes + static_cast<int>(simple_rand() % (step + 1)) - static_cast<int>(step / 2);
            int newDest = destroy + static_cast<int>(simple_rand() % (step + 1)) - static_cast<int>(step / 2);
            if (newHole < 0)
                newHole = 0;
            if (newHeight < 0)
                newHeight = 0;
            if (newHoles < 0)
                newHoles = 0;
            if (newDest < 0)
                newDest = 0;
            if (newHole > 1000)
                newHole = 1000;
            if (newHeight > 1000)
                newHeight = 1000;
            if (newHoles > 1000)
                newHoles = 1000;
            if (newDest > 1000)
                newDest = 1000;
            sons->add(AI(newHole, newHeight, newHoles, newDest));
        }


        for (size_t i = 0; i < sons->sizes(); ++i) {
            std::cout << i << '\n';
            (*sons)[i].show();
        }
    }

    void show() const {
        cout << "AI: " << sonsAmount << " " << hole << " " << height << " " << moreThan3Holes << " " << destroy << " "<< step << " "
             << endl;
    }

    AI(const AI &copy) :
            hole(copy.hole), height(copy.height), moreThan3Holes(copy.moreThan3Holes), sonsAmount(copy.sonsAmount), destroy(copy.destroy),
            step(copy.step) {
        sons = new Sequence<AI>(copy.sonsAmount);
        for (size_t i = 0; i < copy.sons->capacity(); ++i) {
            (*sons)[i] = (*(copy.sons))[i];
        }
    };

    AI(const int hole, const int height, const int moreThan3Holes, const int dest) :
            hole(hole), height(height), moreThan3Holes(moreThan3Holes), sonsAmount(0), destroy(dest), step(0) {

    };
    Sequence<AI> *sons = new Sequence<AI>;;

};


#endif //AI_TETRIS_AI_H
