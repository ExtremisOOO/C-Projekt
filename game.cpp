#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "labirynt.cpp"
#ifdef _WIN32
#include <windows.h>
#endif


class Game {
    Labirynt lab;
    Gracz gracz;
    Przeciwnik prz;
    int solved;
public:
    Game(int width, int height)
      : lab(width, height), gracz(1,1), prz(width-2, height-2), solved(0) {}
    void run() {
        lab.generate(3,3);
        bool win=false, lose=false;
        while(!win && !lose) {
            lab.print(gracz, prz);
            std::cout<<"Ruch (W/A/S/D): ";
            gracz.move(lab.getMap(), prz);
            int gx=gracz.getX(), gy=gracz.getY();
            if(lab.get(gy,gx)=='T'){ std::cout<<"Pulapka! Przegrana.\n"; lose=true; break; }
            if(lab.get(gy,gx)=='P'){
                int a=std::rand()%10, b=std::rand()%10;
                std::cout<<"Zagadka: "<<a<<" + "<<b<<" = ";
                int ans; std::cin>>ans;
                if(ans == a+b) {
                    std::cout<<"Dobrze!\n";
                    lab.set(gy,gx,' ');
                    solved++;
                    if(solved==3){
                        int cx, cy;
                        do {
                            cx=std::rand()%(lab.getWidth()-2)+1;
                            cy=std::rand()%(lab.getHeight()-2)+1;
                        } while(lab.get(cy,cx)!=' ');
                        lab.set(cy,cx,'C');
                        std::cout<<"Pojawila sie skrzynka!\n";
                    }
                } else {
                    std::cout<<"Zle. Sprobuj pozniej.\n";
                }
            }
            if(lab.get(gy,gx)=='C'){ std::cout<<"Skrzynka! Wygrana!\n"; win=true; break; }
            prz.move(lab.getMap(), gracz);
            if(prz.getX()==gracz.getX() && prz.getY()==gracz.getY()){
                std::cout<<"Przeciwnik Cie zlapal! Przegrana.\n";
                lose=true; break;
            }
        }
        if(win) std::cout<<"Koniec gry: Wygrana!\n";
        if(lose) std::cout<<"Koniec gry: Przegrana!\n";
        std::cout<<"Nacisnij ENTER, by zakonczyc.";
        std::cin.ignore(); std::cin.get();
    }
};