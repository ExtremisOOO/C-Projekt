#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "game.cpp"
#ifdef _WIN32
#include <windows.h>
#endif



int main(){
    std::srand(std::time(nullptr));
    Game gra(40,20);
    gra.run();
    return 0;
}