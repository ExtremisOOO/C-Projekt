#pragma once
#include "Postac.h"

// -----------------------------------------------------------------------------
// Przeciwnik
class Przeciwnik : public Postac {
public:
    Przeciwnik(int x, int y) : Postac(x,y,'O') {}

    void move(const std::vector<std::vector<char>>& map, const Postac& target) override {
        int px = target.getX(), py = target.getY();
        int dx = (px > getX()) ? 1 : (px < getX() ? -1 : 0);
        int dy = (py > getY()) ? 1 : (py < getY() ? -1 : 0);
        int nx = getX() + dx;
        int ny = getY() + dy;
        if(ny>=0 && ny<map.size() && nx>=0 && nx<map[0].size()) {
            if(map[ny][nx] != '|' && map[ny][nx] != '_') {
                pos.set(nx, ny);
            }
        }
    }
};
