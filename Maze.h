#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include "MazeCell.h"
#include "Trap.h"
#include "MathPuzzle.h"
#include "Gracz.h"
#include "Przeciwnik.h"

// -----------------------------------------------------------------------------
// Maze
class Maze {
    int width, height;
    std::vector<std::vector<MazeCell>> cells;
public:
    std::vector<std::vector<char>> map;

    Maze(int w, int h) : width(w), height(h), map(h, std::vector<char>(w,' ')) {
        cells.reserve(h);
        for(int y=0; y<h; y++){
            std::vector<MazeCell> row;
            row.reserve(w);
            for(int x=0; x<w; x++){
                row.emplace_back(x, y);
            }
            cells.push_back(std::move(row));
        }
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    const std::vector<std::vector<char>>& getMap() const { return map; }
    MazeCell& cell(int y, int x) { return cells[y][x]; }

    void generate(int puzzlesCount, int trapsCount) {
        for(int x=0; x<width; x++){
            map[0][x] = '_';
            map[height-1][x] = '_';
        }
        for(int y=0; y<height; y++){
            map[y][0] = '|';
            map[y][width-1] = '|';
        }

        for(int y=1; y<height-1; y++){
            for(int x=1; x<width-1; x++){
                if(std::rand()%10 == 0) map[y][x] = '|';
                else map[y][x] = ' ';
            }
        }

        for(int k=0; k<trapsCount; k++){
            int px, py;
            do {
                px = std::rand()%(width-2)+1;
                py = std::rand()%(height-2)+1;
            } while(map[py][px] != ' ');
            cells[py][px].content = std::make_unique<Trap>();
            map[py][px] = 'T';
        }

        for(int k=0; k<puzzlesCount; k++){
            int px, py;
            do {
                px = std::rand()%(width-2)+1;
                py = std::rand()%(height-2)+1;
            } while(map[py][px] != ' ');
            cells[py][px].content = std::make_unique<MathPuzzle>();
            map[py][px] = 'P';
        }
    }

    void print(const Gracz& player, const std::vector<std::unique_ptr<Postac>>& enemies) const {
        system("cls");
        for(int y=0; y<height; y++){
            for(int x=0; x<width; x++){
                if(x==player.getX() && y==player.getY()){
                    std::cout << player.getSymbol();
                } else {
                    bool printed = false;
                    for(const auto& e : enemies){
                        if(x==e->getX() && y==e->getY()){
                            std::cout << e->getSymbol();
                            printed = true; break;
                        }
                    }
                    if(!printed){
                        std::cout << map[y][x];
                    }
                }
            }
            std::cout << "\n";
        }
    }
};
