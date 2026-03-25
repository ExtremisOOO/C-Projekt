#pragma once
#include <iostream>
#include <memory>
#include "ITriggerable.h"
#include "Gracz.h"
#include "Item.h"

// -----------------------------------------------------------------------------
// Treasure
class Treasure : public ITriggerable {
public:
    void trigger(Gracz& p) override {
        std::cout << "Znalazles skarb! Dodano przedmiot do ekwipunku.\n";
        p.getInventory().addItem(std::make_unique<Item>("Zloty Klucz"));
    }
};
