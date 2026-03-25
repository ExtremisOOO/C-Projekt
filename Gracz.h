#pragma once
#include <iostream>
#include "Postac.h"
#include "Inventory.h"

// -----------------------------------------------------------------------------
// Gracz
class Gracz : public Postac {
    Inventory inventory;
public:
    Gracz(int x, int y) : Postac(x,y,'X') {}

    void move(const std::vector<std::vector<char>>& map, const Postac&) override {
        char dir; std::cin >> dir;
        int nx = getX(), ny = getY();
        if(dir=='W' || dir=='w') ny--;
        if(dir=='S' || dir=='s') ny++;
        if(dir=='A' || dir=='a') nx--;
        if(dir=='D' || dir=='d') nx++;
        if(ny<0 || ny>=map.size() || nx<0 || nx>=map[0].size()) return;
        if(map[ny][nx]=='|' || map[ny][nx]=='_') return;
        pos.set(nx, ny);
    }

    Inventory& getInventory() { return inventory; }
    void printInventory() const { inventory.print(); }
};
