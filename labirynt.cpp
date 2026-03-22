#include <iostream>
#include <vector>
#include "postac.cpp"
// -------------------------
// Klasa Labirynt (plansza)
// -------------------------

class Labirynt {
    std::vector<std::vector<char>> map;
public:
    Labirynt(int width, int height)
      : map(height, std::vector<char>(width, ' ')) {}
    void generate(int puzzlesCount, int trapsCount) {
        int h = map.size(), w = map[0].size();
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                map[i][j] = ' ';
        for(int i=0;i<w;i++){ map[0][i]='_'; map[h-1][i]='_'; }
        for(int i=0;i<h;i++){ map[i][0]='|'; map[i][w-1]='|'; }
        for(int i=1;i<h-1;i++){
            for(int j=1;j<w-1;j++){
                if (std::rand()%10 == 0) map[i][j] = '|';
            }
        }
        for(int k=0;k<trapsCount;k++){
            int px = std::rand()%(w-2)+1, py = std::rand()%(h-2)+1;
            if(map[py][px]==' ') map[py][px] = 'T';
        }
        for(int k=0;k<puzzlesCount;k++){
            int px = std::rand()%(w-2)+1, py = std::rand()%(h-2)+1;
            if(map[py][px]==' ') map[py][px] = 'P';
        }
    }
    char get(int y,int x) const { return map[y][x]; }
    void set(int y,int x,char c) { map[y][x] = c; }
    int getWidth() const { return map[0].size(); }
    int getHeight() const { return map.size(); }
    const std::vector<std::vector<char>>& getMap() const { return map; }
    void print(const Postac& gracz, const Postac& prz) const {
        #ifdef _WIN32
        system("cls");
        #else
        std::cout << "\033[2J\033[1;1H";
        #endif
        for(int i=0;i<map.size();i++){
            for(int j=0;j<map[0].size();j++){
                if (i==gracz.getY() && j==gracz.getX()) std::cout<<gracz.getSymbol();
                else if (i==prz.getY() && j==prz.getX()) std::cout<<prz.getSymbol();
                else std::cout<<map[i][j];
            }
            std::cout<<"\n";
        }
    }
};