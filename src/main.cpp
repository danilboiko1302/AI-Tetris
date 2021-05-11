#include <iostream>
#include "AI.h"
#include <cstdlib>



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
    for(int i = 0; i< 1; ++i){
        int a = simple_rand() % 100;
        int b = simple_rand() % 100;
        int c = simple_rand() % 100;
        int d = simple_rand() % 100;
        AI *e = new AI(1, 700, 65 , 4, 19, 0);
        unsigned long long res = e->start();
        if(res > max){
            max = res;
            aR = a;
            bR = b;
            cR = c;
            dR = d;
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "MAx " << max <<endl;
    cout<< "a "<< aR <<endl;
    cout<< "b "<< bR <<endl;
    cout<< "c "<< cR <<endl;
    cout<< "d "<< dR <<endl;




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
