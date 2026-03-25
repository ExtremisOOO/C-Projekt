#include <ctime>
#include <cstdlib>
#include "Game.h"

// -----------------------------------------------------------------------------
// main
int main(){
    std::srand(std::time(nullptr));
    Game gra(40, 20);
    gra.run();
    return 0;
}
