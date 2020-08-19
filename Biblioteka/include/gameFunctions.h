#ifndef SNAKE_GAMEFUNCTIONS_H
#define SNAKE_GAMEFUNCTIONS_H

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include <list>
#include "Snake.h"
#include "Food.h"

void checkEvents(sf::Event &, sf::RenderWindow &, sf::Vector2f &);
void createWindow(sf::RenderWindow &, Settings &);
void snakeMove(std::list<Snake> &, sf::Time &, Settings &, Snake &, sf::Vector2f &);
void collisions(std::list<Snake> &, FoodPtr &, sf::Vector2f &, Settings &, int &, Snake &);
void checkWalls(std::list<Snake> &, sf::RenderWindow &, bool &);

#endif //SNAKE_GAMEFUNCTIONS_H
