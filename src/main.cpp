#include <iostream>
#include "Game.h"
int main() {
    srand(time(0));
    Game* a = new Game();
    a->seeBord();
    a->moveRight();
    cout<<endl;
    a->seeBord();
    a->moveRight();
    cout<<endl;
    a->seeBord();
    a->moveRight();
    cout<<endl;
    a->seeBord();
    a->moveRight();
    cout<<endl;
    a->seeBord();
    a->moveRight();
    cout<<endl;
    a->seeBord();
    Shape* b = new O();

    return 0;
}
