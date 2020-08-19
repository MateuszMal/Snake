#ifndef SNAKE_GAMEFUNCTIONS_H
#define SNAKE_GAMEFUNCTIONS_H

#include <SFML/Graphics.hpp>
#include "Settings.h"

void checkEvents(sf::Event &, sf::Window &, sf::Vector2f &);
void createWindow(sf::Window &, Settings &);

#endif //SNAKE_GAMEFUNCTIONS_H
