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
#include "Options.h"

using namespace sf;

int main(){

    //TODO zrobic funkcje zakonczajaca gre

    srand(time(nullptr));
    setlocale(LC_ALL, "");

    RenderWindow Okno;
    Settings settings;
    //gameState state = gameState::MENU;
    Menu menu(settings.getWWidth(), settings.getWHeight(), settings.getFont());
    menu.setText();
    Options options(settings.getWWidth(), settings.getWHeight(), settings.getFont());
    options.setText();
    Clock clock;
    Time remainingTime;

    createWindow(Okno, settings);

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
//            if (settings.isOption()) optionsEvents(Zdarzenie, options, Okno, settings);
//            else {
//                if (settings.isMenu()) menuEvents(Zdarzenie, menu, Okno, settings);
//                else checkEvents(Zdarzenie, Okno, moveDirect);
            switch(settings.getState()){
                case gameState::PLAY:
                    checkEvents(Zdarzenie, Okno, moveDirect);
                    break;
                case gameState::MENU:
                    menuEvents(Zdarzenie, menu, Okno, settings);
                    break;
                case gameState::OPTIONS:
                    optionsEvents(Zdarzenie, options, Okno, settings);
                    break;
                case gameState::CONTROLS:
                    break;
                case gameState::SCREEN_SIZE:
                    break;

            }
        }
        switch(settings.getState()) {
            case gameState::PLAY:
                Okno.clear(Color::Black);

                // Add the time since the last update
                remainingTime += clock.restart();

                drawSnake(Okno, weze);

                snakeMove(weze, remainingTime, settings, waz, moveDirect);

                collisions(weze, jablko, moveDirect, settings, score, waz);

                checkWalls(weze, Okno, settings);

                Okno.draw(*jablko);

                textScores(Okno, score, text, settings.getFont());
                drawScores(Okno, text);
                break;
            case gameState::MENU:
                Okno.clear(Color::Black);
                menu.draw(Okno);
                break;
            case gameState::OPTIONS:
                Okno.clear(Color::Black);
                options.draw(Okno);
                break;
            case gameState::CONTROLS:
                break;
            case gameState::SCREEN_SIZE:
                break;
        }

//        //Mozna by to wykorzystac do pauzy
//        if (settings.getState() == gameState::OPTIONS) {
//            Okno.clear(Color::Black);
//            options.draw(Okno);
//        }
//        else {
//            if (settings.getState() == gameState::MENU) {
//                Okno.clear(Color::Black);
//                menu.draw(Okno);
//            }
//            else {
//                    Okno.clear(Color::Black);
//
//                    // Add the time since the last update
//                    remainingTime += clock.restart();
//
//                    drawSnake(Okno, weze);
//
//                    snakeMove(weze, remainingTime, settings, waz, moveDirect);
//
//                    collisions(weze, jablko, moveDirect, settings, score, waz);
//
//                    checkWalls(weze, Okno, settings);
////                    std::cout << "checkwalls: " << settings.isMenu() << std::endl;
////                    std:: cout << options.getSelectedItem() << std::endl;
//
////                    eatSnake(weze, waz);
//
////            std::cout << "Ilosc klatek: " <<settings.getSpeed() << std::endl;
////            std::cout << "Score: " << score << std::endl;
//                    Okno.draw(*jablko);
//
//                    textScores(Okno, score, text, settings.getFont());
//                    drawScores(Okno, text);
//
//                }
//            }
        Okno.display();
    }
    return 0;
}