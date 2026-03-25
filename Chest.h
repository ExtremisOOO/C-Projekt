#pragma once
#include <iostream>
#include "ITriggerable.h"
#include "Gracz.h"

// -----------------------------------------------------------------------------
// Chest
class Chest : public ITriggerable {
public:
    void trigger(Gracz& p) override {
        std::cout << "Skrzynka! Wygrales!\n";
    }
};
