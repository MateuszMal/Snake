#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <string>
#include "Settings.h"
#include "Snake.h"
#include "Food.h"
#include "gameFunctions.h"
#include "Menu.h"

using namespace sf;

int main(){

    srand(time(NULL));
    setlocale(LC_ALL, "");

    RenderWindow Okno;
    Settings settings;
    Menu menu(settings.getWWidth(), settings.getWHeight(), settings.getFont());

    //clock and accumulator time for timming
    Clock clock;
    Time remainingTime;

    createWindow(Okno, settings);

    bool game = false;
    int score = 0;
    Text text;
    Snake waz(20);
    std::list<Snake> weze;
    weze.push_back(waz);
    FoodPtr jablko = std::make_shared<Food>(10);

    Vector2f moveDirect(0,0);

    Event Zdarzenie;

    while(Okno.isOpen()) {
        while (Okno.pollEvent(Zdarzenie)) {
            if(!game) menuEvents(Zdarzenie, menu, Okno, game);
            else checkEvents(Zdarzenie, Okno, moveDirect);

        }
        Okno.clear(Color::Black);

        //Mozna by to wykorzystac do pauzy
        if(!game) {
            menu.draw(Okno);}
        else {
            
             Okno.clear(Color::Black);

            // Add the time since the last update
            remainingTime += clock.restart();

            drawSnake(Okno, weze);
            std::cout << "draw: " << game << std::endl;
            snakeMove(weze,remainingTime,settings,waz,moveDirect);
            std::cout << "snakeMove: " << game << std::endl;
            collisions(weze,jablko,moveDirect,settings,score,waz);
            std::cout << "collisions: " << game << std::endl;
            checkWalls(weze,Okno,game);
            std::cout << "checkwalls: " << game << std::endl;


//            std::cout << "Ilosc klatek: " <<settings.getSpeed() << std::endl;
//            std::cout << "Score: " << score << std::endl;


            Okno.draw(*jablko);

            textScores(Okno,score,text, settings.getFont());
            drawScores(Okno, text);

        }
        Okno.display();
    }
    return 0;
}