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
    for (int i = 0; i < 100; ++i) {
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
    ofstream myfile;
    myfile.open("log.txt", std::fstream::app);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    if (max > 500) {
        myfile << "Max " << max << endl;
        myfile << "Holes " << aR << endl;
        myfile << "Height " << bR << endl;
        myfile << "Columns " << cR << endl;
        myfile << "Destroy " << dR << endl;
        myfile << endl;
        cout << "MAx " << max << endl;
        cout << "a " << aR << endl;
        cout << "b " << bR << endl;
        cout << "c " << cR << endl;
        cout << "d " << dR << endl;
    }
    myfile.close();
}


int main() {
    srand(time(0));
    test();
    return 0;
}
