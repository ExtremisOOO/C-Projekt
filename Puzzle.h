#pragma once
#include <iostream>
#include <cstdlib>
#include "ITriggerable.h"
#include "Gracz.h"

// -----------------------------------------------------------------------------
// Puzzle
class Puzzle : public ITriggerable {
public:
    void trigger(Gracz& p) override {
        int a = std::rand()%10, b = std::rand()%10;
        std::cout << "Zagadka: " << a << " + " << b << " = ";
        int ans; std::cin >> ans;
        if(ans == a+b) std::cout << "Dobrze!\n";
        else std::cout << "Zle.\n";
    }
};
