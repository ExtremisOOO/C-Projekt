#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <string>
#include "Maze.h"
#include "Chest.h"
#include "Treasure.h"
#include "Puzzle.h"
#include "Trap.h"
#include "MathPuzzle.h"
#include "Gracz.h"
#include "Przeciwnik.h"

// -----------------------------------------------------------------------------
// Game
class Game {
    Maze maze;
    Gracz player;
    std::vector<std::unique_ptr<Postac>> enemies;
    int solved = 0;
    bool win = false, lose = false;

    void giveRandomReward() {
        static const std::vector<std::string> rewards = {
            "Zloty Klucz", "Mikstura", "Stary Miecz", "Amulet", "Perla"
        };
        std::string itemName = rewards[std::rand() % rewards.size()];
        player.getInventory().addItem(std::make_unique<Item>(itemName));
        std::cout << "Nagroda za zagadke: " << itemName << "\n";
    }

public:
    Game(int w, int h) : maze(w,h), player(1,1) {
       // enemies.emplace_back(std::make_unique<Przeciwnik>(w-2, h-2));
       // enemies.emplace_back(std::make_unique<Przeciwnik>(w/2, h/2));
        maze.generate(3,3);
    }

    void run() {
        while(!win && !lose) {
            maze.print(player, enemies);
            player.printInventory();
            std::cout << "Ruch (W/A/S/D): ";

            player.move(maze.getMap(), player);
            int px = player.getX(), py = player.getY();

            MazeCell& cell = maze.cell(py, px);
            if(cell.content){
                cell.content->trigger(player);

                if(dynamic_cast<Trap*>(cell.content.get())){
                    lose = true;
                }
                else if(dynamic_cast<Puzzle*>(cell.content.get())){
                    solved++;
                    giveRandomReward();
                    cell.content.reset();
                    maze.map[py][px] = ' ';

                    if(solved == 3){
                        int cx, cy;
                        do {
                            cx = std::rand()%(maze.getWidth()-2)+1;
                            cy = std::rand()%(maze.getHeight()-2)+1;
                        } while(maze.getMap()[cy][cx] != ' ' || (cx==px && cy==py));
                        maze.cell(cy, cx).content = std::make_unique<Chest>();
                        maze.map[cy][cx] = 'C';
                    }
                }
                else if(dynamic_cast<Chest*>(cell.content.get())){
                    win = true;
                }
            }

            for(auto& e : enemies){
                e->move(maze.getMap(), player);
                if(e->getX()==px && e->getY()==py){
                    std::cout << "Przeciwnik Cie zlapal! Przegrywasz.\n";
                    lose = true;
                }
            }
        }

        if(win)  std::cout << "Koniec gry: Wygrales!\n";
        if(lose) std::cout << "Koniec gry: Przegrales!\n";
        std::cout << "Nacisnij ENTER, aby zakonczyc.";
        std::cin.ignore();
        std::cin.get();
    }
};
