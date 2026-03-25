#pragma once
#include <iostream>
#include "ITriggerable.h"
#include "Gracz.h"

// -----------------------------------------------------------------------------
// Trap
class Trap : public ITriggerable {
public:
    void trigger(Gracz& p) override {
        std::cout << "Pulapka! Przegrywasz.\n";
    }
};
