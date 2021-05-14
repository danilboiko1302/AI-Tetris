//
// Created by User on 5/9/2021.
//

#include "AI.h"

AI::AI() : hole(50), height(50), moreThan3Holes(50), sonsAmount(50), destroy(50), step(50), simpleShapes(true) {};

AI::AI(const int son, const int hole, const int height, const int moreThan3Holes, const int destroy,
       const int step, bool simple) :
        hole(hole), height(height), moreThan3Holes(moreThan3Holes),
        sonsAmount(son), destroy(destroy), step(step), simpleShapes(simple) {

};

AI &AI::operator=(const AI &copy) {
    if (this == &copy)
        return *this;
    hole = copy.hole;
    height = copy.height;
    moreThan3Holes = copy.moreThan3Holes;
    sonsAmount = copy.sonsAmount;
    simpleShapes = copy.simpleShapes;
    destroy = copy.destroy;
    step = copy.step;
    return *this;
};

unsigned long AI::start() {
    createSons();
    return sonsPlay();
}

unsigned long AI::sonsPlay() {
    unsigned long max = 0;

    for (size_t i = 0; i < sons->sizes(); ++i) {
        auto *game = new AIGame((*sons)[i].simpleShapes);
        game->play();
        while (true) {
            auto *positionsBoard = &allBoards(*(game->getShapeClass()), (game->getBoard()));
            auto *scores = new Sequence<int>;
            for (int j = 0; j < positionsBoard->sizes(); ++j) {
                scores->add(scoreBoard((*positionsBoard)[j], (*sons)[i].hole, (*sons)[i].height,
                                       (*sons)[i].moreThan3Holes, (*sons)[i].destroy));
            }
            int min = (*scores)[0];
            for (int j = 1; j < scores->sizes(); ++j)
                if ((*scores)[j] < min)
                    min = (*scores)[j];

            for (int j = 0; j < scores->sizes(); ++j)
                if ((*scores)[j] == min) {
                    game->setBoard((*positionsBoard)[j]);
                    break;
                }
            delete positionsBoard;
            delete scores;
            game->destroyLine();
            if (game->addShape()) {
                game->seeShape();
            } else {
                if (game->score > max)
                    max = game->score;
                break;
            }
        }
        delete game;
    }
    //cout << "MAX Score is " << max << endl;
    return max;
}

Sequence<array<bool, Game::size * 10>> &AI::allBoards(Shape &shape, array<bool, Game::size * 10> board) {
    auto *test = new Sequence<array<bool, Game::size * 10>>;
    for (int i :  shape.current) {
        board.at(i) = false;
    }
    array<array<int, 4>, 4> shapes{};
    shapes.at(0) = shape.current;
    shapes.at(1) = shape.isTurnPossible();
    shape.current = shape.isTurnPossible();
    shape.rotate();
    shapes.at(2) = shape.isTurnPossible();
    shape.current = shape.isTurnPossible();
    shape.rotate();
    shapes.at(3) = shape.isTurnPossible();

    for (array<int, 4> tempShape : shapes) {
        int maxWidth = 0;
        int maxHeight = 0;
        for (int i :  tempShape) {
            if (i % 10 > maxWidth)
                maxWidth = i % 10;
            if (i / 10 > maxHeight)
                maxHeight = i / 10;
        }
        int max = maxHeight * 10 + maxWidth;
        int widthI = width(tempShape);
        int heightI = heightShape(tempShape);
        int start = Game::size - 1;
        for (int j = 9; j >= widthI - 1; --j) {// line
            for (int i = start; i >= heightI - 1; --i) { //column
                auto temp = board;
                int move = i * 10 + j - max;
                bool suc = true;
                for (int k :  tempShape) {
                    if (temp.at(k + move)) {
                        suc = false;
                        break;
                    }
                }
                if (suc) {
                    for (int k :  tempShape) {
                        temp.at(k + move) = true;
                    }
                    array<int, 4> newShape{};
                    for (int k = 0; k < tempShape.size(); ++k)
                        newShape.at(k) = (tempShape.at(k) + move);

                    if (checkBoard(newShape, temp)) {
                        if (!test->contains(temp)) {
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

bool AI::checkBoard(array<int, 4> shape, array<bool, Game::size * 10> board) {

    for (int k :  shape) {
        if (k + 10 > board.size()) {
            return true;
        } else {
            if (find(std::begin(shape), end(shape), k + 10) != end(shape)) {
                if (board.at(k + 10)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int AI::width(array<int, 4> shape) {
    int min = 9;
    int max = 0;
    for (int i :  shape) {
        if (i % 10 > max)
            max = i % 10;
        if (i % 10 < min)
            min = i % 10;
    }
    return max - min + 1;
}

int AI::heightShape(array<int, 4> shape) {
    int min = 9;
    int max = 0;
    for (int i :  shape) {
        if (i / 10 > max)
            max = i / 10;
        if (i / 10 < min)
            min = i / 10;
    }
    return max - min + 1;
}

int AI::scoreBoard(array<bool, Game::size * 10> ar, int hole, int height, int more3, int dest) {
    return countHoles(ar) * hole + countHeight(ar) * height + countColumns(ar) * more3 - countDestroy(ar) * dest;
}

int AI::countDestroy(array<bool, Game::size * 10> ar) {
    int res = 0;
    for (int i = 0; i < ar.size() / 10; ++i) {
        bool line = true;
        for (int j = 0; j < 10; ++j) {
            line = line && ar.at(i * 10 + j);
        }
        if (line)
            res++;
    }
    return res;
}

int AI::countHoles(array<bool, Game::size * 10> ar) {
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

int AI::countHeight(array<bool, Game::size * 10> ar) {
    for (int i = 0; i < ar.size(); ++i)
        if (ar[i]) {
            return int(Game::size) - i / 10;
        }

    return 0;
}

int AI::countColumns(array<bool, Game::size * 10> ar) {
    int col = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = i; j < ar.size(); j += 10) {
            if (ar[j]) {
                break;
            }
            if (i == 0) {
                if (ar.at(j + 1)) {
                    if (int(Game::size) - j / 10 > 3) {
                        col += int(Game::size) - j / 10 - 2;
                    }
                }
            } else if (i == 9) {
                if (ar.at(j - 1)) {
                    if (int(Game::size) - j / 10 > 3) {
                        col += int(Game::size) - j / 10 - 2;
                    }
                }
            } else {
                if (ar.at(j - 1) && ar.at(j + 1)) {
                    if (int(Game::size) - j / 10 > 3) {
                        col += int(Game::size) - j / 10 - 2;
                    }
                }
            }
        }
    }
    return col;
}

void AI::seeBoard(array<bool, Game::size * 10> ar) {
    for (int i = 0; i < ar.max_size(); ++i) {
        if (i % 10 == 0) {
            cout << endl;
        }
        cout << ar.at(i);
    }
    cout << endl;
}

bool AI::turn(AIGame &game) {
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

void AI::goToLeftSide(AIGame &game) {
    array<bool, Game::size * 10> board{};
    array<bool, Game::size * 10> newBoard{};

    do {
        board = game.getBoard();
        game.moveLeft();
        newBoard = game.getBoard();
    } while (board != newBoard);
}

void AI::createSons() {
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
        sons->add(AI(newHole, newHeight, newHoles, newDest, simpleShapes));
    }


    for (size_t i = 0; i < sons->sizes(); ++i) {
        //std::cout << i << '\n';
        //(*sons)[i].show();
    }
}

void AI::show() const {
    cout << "AI: " << sonsAmount << " " << hole << " " << height << " " << moreThan3Holes << " " << destroy << " "
         << step << " "
         << endl;
}

AI::AI(const AI &copy) :
        hole(copy.hole), height(copy.height), moreThan3Holes(copy.moreThan3Holes), sonsAmount(copy.sonsAmount),
        destroy(copy.destroy),
        step(copy.step),
        simpleShapes(copy.simpleShapes){
    sons = new Sequence<AI>(copy.sonsAmount);
    for (size_t i = 0; i < copy.sons->capacity(); ++i) {
        (*sons)[i] = (*(copy.sons))[i];
    }
}

AI::AI(const int hole, const int height, const int moreThan3Holes, const int dest, const bool simp) :
        hole(hole), height(height), moreThan3Holes(moreThan3Holes), sonsAmount(0), destroy(dest), step(0), simpleShapes(simp) {

};