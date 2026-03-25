#pragma once
#include <vector>
#include "Point.h"

// -----------------------------------------------------------------------------
// Postac
class Postac {
protected:
    Point pos;
    char symbol;
public:
    Postac(int x, int y, char sym) : pos(x,y), symbol(sym) {}
    virtual ~Postac() = default;
    virtual void move(const std::vector<std::vector<char>>& map, const Postac& target) = 0;
    int getX() const { return pos.x; }
    int getY() const { return pos.y; }
    char getSymbol() const { return symbol; }
};
