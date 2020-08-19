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

    Snake waz(20);
    std::list<Snake> weze;
    weze.push_back(waz);

    createWindow(Okno, settings);

    bool game = true;
    int score = 0;

    FoodPtr jablko = std::make_shared<Food>(10);

    Vector2f moveDirect(0,0);

    Event Zdarzenie;

    while(Okno.isOpen() && game) {
        while (Okno.pollEvent(Zdarzenie)) {
            checkEvents(Zdarzenie, Okno, moveDirect);
        }

        // Add the time since the last update
        remainingTime += clock.restart();

        while(remainingTime > milliseconds(settings.getSpeed())) {

            if (weze.size() > 1) {
                weze.pop_back();
                waz.setPosition(weze.begin()->getPosition());
                weze.push_front(waz);
            }
            weze.begin()->move(moveDirect);

            remainingTime -= milliseconds(settings.getSpeed());
        }
        Okno.clear(Color::Black);

        if (weze.begin()->eatFood(*jablko)) {
                waz.setPosition(weze.back().getPosition().x - moveDirect.x,
                                weze.back().getPosition().y - moveDirect.y);
                weze.push_back(waz);
                score += 100;
                //Increasing snake when he's growing
                settings.setSpeed(settings.getSpeed() - weze.size() * 2);
            }


        for(auto & w : weze){
            if(w.wallCollision(Okno)) game = false;
            //Need to think about this
            //if(weze.begin()->eatYourself(w)) game = false;
            Okno.draw(w);
        }

        //std::cout << score << std::endl;
        std::cout << settings.getSpeed() << std::endl;
        Okno.draw(*jablko);
        Okno.display();
    }
    return 0;
}