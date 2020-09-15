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
void snakeMove(std::list<SnakePtr> &, sf::Time &, Settings &, sf::Vector2f &);
void collisions(std::list<SnakePtr> &, FoodPtr &, sf::Vector2f &, Settings &);
void checkWalls(std::list<SnakePtr> &, sf::RenderWindow &, Settings &);
void menuEvents(sf::Event &, Menu &, sf::RenderWindow &, Settings &);
void textScores(sf::RenderWindow &, Settings &, sf::Text &);
void drawScores(sf::RenderWindow &, sf::Text &);
void drawSnake(sf::RenderWindow &, std::list<SnakePtr> &);
void optionsEvents(sf::Event &, Options &,sf::RenderWindow &, Settings &);
void changeColor(sf::Event &, Menu &, sf::RenderWindow &, Settings &, sf::CircleShape &);
void changeColor(sf::Event &, Menu &, sf::RenderWindow &, Settings &, sf::RectangleShape &);
void textMoves(sf::Event &, Menu &, sf::RenderWindow &);
void gameOverEvents(sf::Event &, sf::RenderWindow &, Settings &, std::list<SnakePtr> &, SnakePtr &, sf::Vector2f &);
void gameOver(sf::RenderWindow &, Settings &);
void newGame(std::list<SnakePtr> &, Settings &, sf::Vector2f &, SnakePtr &);

#endif //SNAKE_GAMEFUNCTIONS_H
