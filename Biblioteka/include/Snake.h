#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <memory>

class Snake : public sf::RectangleShape{
    unsigned int size;
public:
    Snake(unsigned int size);
    ~Snake() = default;
    bool eatFood(sf::CircleShape & C);
    bool wallCollision(sf::RenderWindow & Okno);
    // Trzeba to inaczej napisać
    bool eatYourself(Snake & S);

    unsigned int getSize1() const;
};

typedef std::shared_ptr<Snake> SnakePtr;


#endif //SNAKE_SNAKE_H
