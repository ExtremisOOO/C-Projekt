#include <iostream>
#include <vector>

class Postac {
protected:
    int x, y;
    char symbol;
public:
    Postac(int x0, int y0, char sym) : x(x0), y(y0), symbol(sym) {}
    virtual ~Postac() {}
    virtual void move(const std::vector<std::vector<char>>& map, const Postac& target) = 0;
    int getX() const { return x; }
    int getY() const { return y; }
    char getSymbol() const { return symbol; }
};

class Gracz : public Postac {
public:
    Gracz(int x0, int y0) : Postac(x0, y0, 'X') {}
    void move(const std::vector<std::vector<char>>& map, const Postac&) override {
        char dir; std::cin >> dir;
        int nx = x, ny = y;
        if (dir=='W'||dir=='w') ny--;
        if (dir=='S'||dir=='s') ny++;
        if (dir=='A'||dir=='a') nx--;
        if (dir=='D'||dir=='d') nx++;
        if (ny<0 || ny>=map.size() || nx<0 || nx>=map[0].size()) return;
        if (map[ny][nx]=='|' || map[ny][nx]=='_') return;
        x = nx; y = ny;
    }
};

class Przeciwnik : public Postac {
public:
    Przeciwnik(int x0, int y0) : Postac(x0, y0, 'O') {}
    void move(const std::vector<std::vector<char>>& map, const Postac& player) override {
        int curDist = abs(x - player.getX()) + abs(y - player.getY());
        std::vector<std::pair<int,int>> moves;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        // Najpierw ruchy zmniejszajace odleglosc
        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (ny<0||ny>=map.size()||nx<0||nx>=map[0].size()) continue;
            if (map[ny][nx]=='|' || map[ny][nx]=='_') continue;
            int dist = abs(nx - player.getX()) + abs(ny - player.getY());
            if (dist < curDist) {
                moves.push_back({nx, ny});
            }
        }
        // Jesli nie ma takich ruchow, dowolny dozwolony
        if (moves.empty()) {
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (ny<0||ny>=map.size()||nx<0||nx>=map[0].size()) continue;
                if (map[ny][nx]=='|' || map[ny][nx]=='_') continue;
                moves.push_back({nx, ny});
            }
        }
        // Wykonaj losowy ruch sposrod dozwolonych
        if (!moves.empty()) {
            auto chosen = moves[std::rand() % moves.size()];
            x = chosen.first; y = chosen.second;
        }
    }
};

