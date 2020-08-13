#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <SFML/Graphics.hpp>
#include <list>
#include <vector>

class Snake : public sf::RectangleShape{
public:
    Snake(int size);
    ~Snake();
    bool eatFood(sf::CircleShape & C);
    bool wallColission(sf::RenderWindow & Okno);
    // Trzeba to inaczej napisać
    bool eatYourself(Snake & S);
};


#endif //SNAKE_SNAKE_H
