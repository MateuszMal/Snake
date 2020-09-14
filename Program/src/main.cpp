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
#include "Controls.h"

using namespace sf;

int main(){

    //TODO zrobic funkcje zakonczajaca gre

    srand(time(nullptr));
    setlocale(LC_ALL, "");

    RenderWindow Okno;
    Settings settings;
    Menu menu(settings.getWWidth(), settings.getWHeight(), settings.getFont());
    menu.setText();
    Options options(settings.getWWidth(), settings.getWHeight(), settings.getFont());
    options.setText();
    Controls controls(settings.getWWidth(), settings.getWHeight(), settings.getFont());
    controls.setText();
    Clock clock;
    Time remainingTime;

    createWindow(Okno, settings);

    Text text;
    Snake waz(20);
    std::list<Snake> weze;
    weze.push_back(waz);
    FoodPtr jablko = std::make_shared<Food>(10);

    Vector2f moveDirect(0,0);

    Event Zdarzenie;

    while(Okno.isOpen()) {
        while (Okno.pollEvent(Zdarzenie)) {

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
                case gameState::FRUIT_COLOR:
                    changeColor(Zdarzenie, controls, Okno, settings, *jablko);
                    break;
                case gameState::SNAKE_COLOR:
                    changeColor(Zdarzenie, controls, Okno, settings, waz);
                    break;
                case gameState ::GAME_OVER:
                    gameOverEvents(Zdarzenie, Okno, settings,weze,waz,moveDirect);
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

                collisions(weze, jablko, moveDirect, settings, waz);

                checkWalls(weze, Okno, settings);

                Okno.draw(*jablko);

                textScores(Okno, settings,text);
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
            case gameState::FRUIT_COLOR:
                Okno.clear(Color::Black);
                controls.draw(Okno);
                break;
            case gameState::SNAKE_COLOR:
                Okno.clear(Color::Black);
                controls.draw(Okno);
                break;
            case gameState ::GAME_OVER:
                gameOver(Okno, settings);
                }
        Okno.display();
    }
    return 0;
}