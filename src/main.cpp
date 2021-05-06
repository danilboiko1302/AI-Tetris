#include <iostream>
#include "Game.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "!!!!!!!!!!!!!!" << std::endl;
    Game* a = new Game();
    cout<<a->ar.max_size()<<endl;
    cout<<a->ar.size()<<endl;
    return 0;
}
