#include <iostream>
#include "AI.h"
#include <cstdlib>
#include <fstream>


void test() {
    //Game* a = new Game();
   // a->play();
    minstd_rand simple_rand;
    simple_rand.seed(time(0));
    for(int j = 0; j< 1; ++j){
        unsigned long long max = 0;
        int aR = 0;
        int bR = 0;
        int cR = 0;
        int dR = 0;
        for(int i = 0; i< 100; ++i){
            int a = simple_rand() % 100;
            int b = simple_rand() % 100;
            int c = simple_rand() % 100;
            int d = simple_rand() % 100;
            AI *e = new AI(1, 79, 49 , 3, 96, 0);
            unsigned long long res = e->start();
            if(res > max){
                max = res;
                aR = a;
                bR = b;
                cR = c;
                dR = d;
            }
        }
        ofstream myfile;
        myfile.open ("log.txt", std::fstream::app);
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
//        myfile << "Max " << max <<endl;
//        myfile<< "Holes "<< aR <<endl;
//        myfile<< "Height "<< bR <<endl;
//        myfile<< "Columns "<< cR <<endl;
//        myfile<< "Destroy "<< dR <<endl;
//        myfile <<endl;
        cout << "MAx " << max <<endl;
        cout<< "a "<< aR <<endl;
        cout<< "b "<< bR <<endl;
        cout<< "c "<< cR <<endl;
        cout<< "d "<< dR <<endl;
        myfile.close();
    }






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
