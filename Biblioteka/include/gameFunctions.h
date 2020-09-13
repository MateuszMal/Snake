#ifndef SNAKE_GAMEFUNCTIONS_H
#define SNAKE_GAMEFUNCTIONS_H

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include <list>
#include "Snake.h"
#include "Food.h"
#include "Menu.h"
#include "Options.h"
#include "Controls.h"

void checkEvents(sf::Event &, sf::RenderWindow &, sf::Vector2f &);
void createWindow(sf::RenderWindow &, Settings &);
void snakeMove(std::list<Snake> &, sf::Time &, Settings &, Snake &, sf::Vector2f &);
void collisions(std::list<Snake> &, FoodPtr &, sf::Vector2f &, Settings &, int &, Snake &);
void checkWalls(std::list<Snake> &, sf::RenderWindow &, Settings &);
void menuEvents(sf::Event &, Menu &, sf::RenderWindow &, Settings &);
void textScores(sf::RenderWindow &, int &, sf::Text &, const sf::Font &);
void drawScores(sf::RenderWindow &, sf::Text &);
void drawSnake(sf::RenderWindow &, std::list<Snake> &);
void optionsEvents(sf::Event &, Options &,sf::RenderWindow &, Settings &);
void changeColor(sf::Event &, Controls &, sf::RenderWindow &, Settings &, FoodPtr &);
void textMoves(sf::Event &, Menu &, sf::RenderWindow &);
//void eatSnake(std::list<Snake> &, Snake &);

#endif //SNAKE_GAMEFUNCTIONS_H
