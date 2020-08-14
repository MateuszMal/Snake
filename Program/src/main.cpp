#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <string>
#include "Settings.h"
#include "Snake.h"
#include "Food.h"

using namespace std;
using namespace sf;



int main(){

    RenderWindow Okno;

    srand(time(NULL));

    setlocale(LC_ALL, "");

    Settings settings;

    Okno.create(VideoMode(settings.getWWidth(),
            settings.getWHeight(),
            settings.getWBitsPerPixel()),
                    "Okno");
    Okno.setActive(true);
    Okno.setKeyRepeatEnabled(false);
    Okno.setFramerateLimit(settings.getFrameLimit());
    Okno.setVerticalSyncEnabled(true);
    Okno.setPosition(Vector2i(10,650));

    bool game = true;

    //clock and accumulator time for timming
    Clock clock;
    Time remainingTime;

    Snake waz(20);
    list<Snake> weze;
    weze.push_back(waz);

    int score = 0;

    FoodPtr jablko = std::make_shared<Food>(10);

    Vector2f moveDirect(0,0);

    Event Zdarzenie;

    while(Okno.isOpen() && game) {
        while (Okno.pollEvent(Zdarzenie)) {
            if(Zdarzenie.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) Okno.close();
            if(Zdarzenie.type == Event::KeyPressed && Zdarzenie.key.code == Keyboard::W) moveDirect=Vector2f(0,-20);
            if(Zdarzenie.type == Event::KeyPressed && Zdarzenie.key.code == Keyboard::S) moveDirect=Vector2f(0,20);
            if(Zdarzenie.type == Event::KeyPressed && Zdarzenie.key.code == Keyboard::A) moveDirect=Vector2f(-20,0);
            if(Zdarzenie.type == Event::KeyPressed && Zdarzenie.key.code == Keyboard::D) moveDirect=Vector2f(20,0);
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
                //zwiekszanie predkosci weza gdy jego dlugosc rosnie
                settings.setSpeed(settings.getSpeed() - weze.size() * 2);
            }



        for(auto & w : weze){
            if(w.wallColission(Okno)) game = false;
            //Do przemyslenia
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