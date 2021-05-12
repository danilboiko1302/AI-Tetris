#include <iostream>
#include "AI.h"
#include <cstdlib>
#include <fstream>


void test() {
    //Game* a = new Game();
    // a->play();
    minstd_rand simple_rand;
    simple_rand.seed(time(nullptr));
    unsigned long long max = 0;
    int holeRes = 0;
    int heightRes = 0;
    int columnsRes = 0;
    int destroyRes = 0;
    int times = 100; //don`t use more than 200
    for (int i = 0; i < times; ++i) {
        cout<<i<<endl;
        int hole = 79;// simple_rand() % 100;
        int height = 49; //simple_rand() % 100;
        int columns = 3; //simple_rand() % 100;
        int destroy = 96;//simple_rand() % 100;
        AI *ai = new AI(1, hole, height, columns, destroy, 0);
        unsigned long long res = ai->start();
        if (res > max) {
            max = res;
            holeRes = hole;
            heightRes = height;
            columnsRes = columns;
            destroyRes = destroy;
        }
        delete ai;
    }
    ofstream log;
    log.open("log.txt", std::fstream::app);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    if (max > 500) {
        log << "Max " << max << endl;
        log << "Holes " << holeRes << endl;
        log << "Height " << heightRes << endl;
        log << "Columns " << columnsRes << endl;
        log << "Destroy " << destroyRes << endl;
        log << endl;
        cout << "Max " << max << endl;
        cout << "Holes " << holeRes << endl;
        cout << "Height " << heightRes << endl;
        cout << "Columns " << columnsRes << endl;
        cout << "Destroy " << destroyRes << endl;
    }
    log.close();
}


int main() {
    srand(time(0));
    test();
    return 0;
}
