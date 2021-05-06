#include <iostream>
#include "Game.h"
int main() {
    srand(time(0));
    Game* a = new Game();
    a->seeBord();


    return 0;
}
