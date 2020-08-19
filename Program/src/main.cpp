#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <string>
#include "Settings.h"
#include "Snake.h"
#include "Food.h"
#include "gameFunctions.h"

using namespace sf;

int main(){

    srand(time(NULL));
    setlocale(LC_ALL, "");

    RenderWindow Okno;
    Settings settings;
    //clock and accumulator time for timming
    Clock clock;
    Time remainingTime;

    createWindow(Okno, settings);

    bool game = true;
    int score = 0;

    Snake waz(20);
    std::list<Snake> weze;
    weze.push_back(waz);
    FoodPtr jablko = std::make_shared<Food>(10);

    Vector2f moveDirect(0,0);

    Event Zdarzenie;

    while(Okno.isOpen() && game) {
        while (Okno.pollEvent(Zdarzenie)) {
            checkEvents(Zdarzenie, Okno, moveDirect);
        }
        Okno.clear(Color::Black);

        // Add the time since the last update
        remainingTime += clock.restart();

        snakeMove(weze,remainingTime,settings,waz,moveDirect);

        collisions(weze,jablko,moveDirect,settings,score,waz);

        checkWalls(weze,Okno,game);

        std::cout << "Ilosc klatek: " <<settings.getSpeed() << std::endl;
        std::cout << "Score: " << score << std::endl;
        Okno.draw(*jablko);
        Okno.display();
    }
    return 0;
}