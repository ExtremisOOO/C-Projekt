#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Item.h"

// -----------------------------------------------------------------------------
// Inventory
class Inventory {
    std::vector<std::unique_ptr<Item>> items;
public:
    void addItem(std::unique_ptr<Item> it) {
        items.push_back(std::move(it));
    }

    void print() const {
        std::cout << "Ekwipunek: ";
        if(items.empty()) {
            std::cout << "(pusty)\n";
            return;
        }
        for(size_t i = 0; i < items.size(); ++i) {
            std::cout << items[i]->getName();
            if(i + 1 < items.size()) std::cout << ", ";
        }
        std::cout << "\n";
    }
};
