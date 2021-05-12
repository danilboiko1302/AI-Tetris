#include <iostream>
#include "AI.h"
#include <cstdlib>
#include <fstream>


void test() {
    //Game* a = new Game();
    // a->play();
    minstd_rand simple_rand;
    simple_rand.seed(time(0));
    unsigned long long max = 0;
    int aR = 0;
    int bR = 0;
    int cR = 0;
    int dR = 0;
    int times = 10;
    for (int i = 0; i < times; ++i) {
        cout<<i<<endl;
        int a = 79;// simple_rand() % 100;
        int b = 49; //simple_rand() % 100;
        int c = 3; //simple_rand() % 100;
        int d = 96;//simple_rand() % 100;
        AI *e = new AI(1, a, b, c, d, 0);
        unsigned long long res = e->start();
        if (res > max) {
            max = res;
            aR = a;
            bR = b;
            cR = c;
            dR = d;
        }
    }
    ofstream log;
    log.open("log.txt", std::fstream::app);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    if (max > 500) {
        log << "Max " << max << endl;
        log << "Holes " << aR << endl;
        log << "Height " << bR << endl;
        log << "Columns " << cR << endl;
        log << "Destroy " << dR << endl;
        log << endl;
        cout << "MAx " << max << endl;
        cout << "a " << aR << endl;
        cout << "b " << bR << endl;
        cout << "c " << cR << endl;
        cout << "d " << dR << endl;
    }
    log.close();
}


int main() {
    srand(time(0));
    test();
    return 0;
}
