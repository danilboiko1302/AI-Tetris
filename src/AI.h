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
            hole(50), height(50), moreThan3Holes(50), sonsAmount(50), step(50) {};

    explicit AI(const int son, const int hole, const int height, const int moreThan3Holes, const int step) :
            hole(hole), height(height), moreThan3Holes(moreThan3Holes), sonsAmount(son), step(step) {

    };

    AI &operator=(const AI &copy) {
        if (this == &copy)
            return *this;
        hole = copy.hole;
        height = copy.height;
        moreThan3Holes = copy.moreThan3Holes;
        sonsAmount = copy.sonsAmount;
        step = copy.step;
        return *this;
    };

    void start() {
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

    void sonsPlay() {
        for (size_t i = 0; i < sons->sizes(); ++i) {
            auto *game = new AIGame();
            auto *positions = new Sequence<array<int, 4>>;
            game->play();
            goToLeftSide(*game);

            array<int, 4> board{};
            array<int, 4> newBoard{};
            do {
                positions->add(*(game->getShape()));
                //game->seeBoard();
                board = *(game->getShape());
                game->moveRight();
                newBoard = *(game->getShape());
            } while (board != newBoard);

            for (int j = 0; j < 3; ++j) {

                //game->seeBoard();
                if (turn(*game)) {
                    //game->seeBoard();
                    do {
                        if (!positions->contains(*(game->getShape())))
                            positions->add(*(game->getShape()));
                        board = *(game->getShape());
                        game->moveRight();
                        newBoard = *(game->getShape());
                    } while (board != newBoard);
                } else {
                    break;
                }

            }
            auto *positionsBoard = new Sequence<array<bool, Game::size * 10>>;
            //game->seeBoard();

            for (int j = 0; j < positions->sizes(); ++j) {
                if (j != 0) {
                    *game->getShape() = (*positions)[j - 1];
                }
                game->removeShape();
                *game->getShape() = (*positions)[j];
                game->seeShape();
                positionsBoard->add(game->nextMoveDown());
                //game->seeBoard();
            }
//             for(int j =0; j<positionsBoard->sizes(); ++j ){
//                 seeBoard((*positionsBoard)[j]);
//             }
            // game->seeBoard();


//             for(int j =0; j<positions->sizes(); ++j ){
//                 for(int k = 0; k < (*positions)[j].max_size(); ++k)
//                     cout<<(*positions)[j].at(k) << endl;
//                 cout << endl;
//             }
            auto *scores = new Sequence<int>;
            for (int j = 0; j < 1; ++j) {
                seeBoard((*positionsBoard)[j]);
                cout << countColumns((*positionsBoard)[j]) << endl;

                //scores->add(scoreBoard((*positionsBoard)[j], (*sons)[i].hole, (*sons)[i].height, (*sons)[i].moreThan3Holes));
            }
//             for(int j =0; j<positionsBoard->sizes(); ++j ){
//                 scores->add(scoreBoard((*positionsBoard)[j], (*sons)[i].hole, (*sons)[i].height, (*sons)[i].moreThan3Holes));
//             }

        }

    }

    static int scoreBoard(array<bool, Game::size * 10> ar, int hole, int height, int more3) {

        return countHoles(ar) * hole + countHeight(ar) * height + countColumns(ar) * more3;
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
        int columns = 0;
        for (int i = 0; i < 10; ++i) {
            bool closed = false;
            for (int j = i; j < ar.size(); j += 10)
                cout << j << endl;
        }
        return columns;
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
            if (newHole < 0)
                newHole = 0;
            if (newHeight < 0)
                newHeight = 0;
            if (newHoles < 0)
                newHoles = 0;
            if (newHole > 100)
                newHole = 100;
            if (newHeight > 100)
                newHeight = 100;
            if (newHoles > 100)
                newHoles = 100;
            sons->add(AI(newHole, newHeight, newHoles));
        }


        for (size_t i = 0; i < sons->sizes(); ++i) {
            std::cout << i << '\n';
            (*sons)[i].show();
        }
    }

    void show() const {
        cout << "AI: " << sonsAmount << " " << hole << " " << height << " " << moreThan3Holes << " " << step << " "
             << endl;
    }

    AI(const AI &copy) :
            hole(copy.hole), height(copy.height), moreThan3Holes(copy.moreThan3Holes), sonsAmount(copy.sonsAmount),
            step(copy.step) {
        sons = new Sequence<AI>(copy.sonsAmount);
        for (size_t i = 0; i < copy.sons->capacity(); ++i) {
            (*sons)[i] = (*(copy.sons))[i];
        }
    };

    AI(const int hole, const int height, const int moreThan3Holes) :
            hole(hole), height(height), moreThan3Holes(moreThan3Holes), sonsAmount(0), step(0) {

    };
    Sequence<AI> *sons = new Sequence<AI>;;

};


#endif //AI_TETRIS_AI_H
