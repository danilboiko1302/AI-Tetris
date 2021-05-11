#include <iostream>
#include "AI.h"
#include <cstdlib>



void test() {
    //Game* a = new Game();
    //a->play();
    minstd_rand simple_rand;
    simple_rand.seed(time(0));

    unsigned long long max = 0;
    for(int i = 0; i< 1; ++i){
        int a = simple_rand() % 100;
        int b = simple_rand() % 100;
        int c = simple_rand() % 100;
        AI *d = new AI(1, a, b , c, 100, 5);
        unsigned long long res = d->start();
        if(res > max){
            max = res;
        }
    }

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << max << endl;


//    a->seeBord();
//    a->moveRight();
//    cout<<endl;
//    a->seeBord();
//    a->moveRight();
//    cout<<endl;
//    a->seeBord();
//    a->moveRight();
//    cout<<endl;
//    a->seeBord();
//    a->moveRight();
//    cout<<endl;
//    a->seeBord();
//    a->moveRight();
//    cout<<endl;
//    a->seeBord();
//    Shape* b = new O();
}


int main() {
    srand(time(0));

    test();

    return 0;
}
