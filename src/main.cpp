#include <iostream>
#include "AI.h"
#include <cstdlib>
int go() {
    try {
        cout << "-----------------------------" << endl;
        cout << "Testing Sequence with int" << endl;

        Sequence<int> sequence;
        cout << "Empty Sequence" << endl;
        sequence.show();
        cout << "Can add Elem with add()" << endl;
        sequence.add(4);
        sequence.add(5);
        sequence.add(1);
        sequence.add(9);
        cout << "Not empty Sequence" << endl;
        sequence.show();
        cout << "Size of Sequence " << endl;
        cout << "Size = " << sequence.sizes() << endl;
        cout << "Operator [] to get or set Elem" << endl;
        cout << "[1] = 6" << endl;
        sequence.show();
        sequence[1] = 6;
        sequence.show();
        cout << "[2]" << endl;
        cout << sequence[2] << endl;
        cout << "Can check whether Sequence empty or full" << endl;
        cout << "Full: " << boolalpha << sequence.full() << endl;
        cout << "Empty: " << boolalpha << sequence.empty() << endl;
        cout << "Can insert Elem on any pos  with insert()" << endl;
        cout << "sequence.insert(3,3);" << endl;
        sequence.show().insert(3, 3).show();
        cout << "Can remove Elem on any pos  with remove()" << endl;
        cout << "sequence.remove(3);" << endl;
        sequence.show().remove(3).show();
        cout << "Can remove Elem last with cut()" << endl;
        cout << "sequence.cut();" << endl;
        sequence.show().cut().show();
        cout << "Can remove Elem first with cutFirst()" << endl;
        cout << "sequence.cutFirst();" << endl;
        sequence.show().cutFirst().show();
        cout << "Can check whether Sequence contains Elem with contains()" << endl;
        sequence.show();
        cout << "contains(6): " << boolalpha << sequence.contains(6) << endl;
        cout << "contains(1): " << boolalpha << sequence.contains(1) << endl;
        cout << "Also out Sequence is endless and we can add 1000 elems" << endl;
        for (size_t i = 0; i < 1000; ++i) {
            sequence.add(i);
        }
        sequence.show();
        cout << "Can clear all Sequence with clear()" << endl;
        cout << "sequence.clear();" << endl;
        sequence.clear().show();

        cout << "If we will try to do something wrong\nFor example we will try to insert Elem on pos -1 or remove Elem with bad pos\nWe will get error" << endl;
        sequence.remove(0);
    }
    catch (const Sequence<int>::BadSeq& x) {

        x.diagnose();
    }

    return 0;
}
void test(){
    //Game* a = new Game();
    //a->play();
    AI* b = new AI(1,50,50,50,10);
    b->start();
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
