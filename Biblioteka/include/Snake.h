#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <SFML/Graphics.hpp>
#include <list>
#include <vector>

class Snake : public sf::RectangleShape{
private:
    int score = 0;
public:
    Snake(int size);
    ~Snake();
    bool eatFood(sf::CircleShape & S);
    bool wallColission(sf::RenderWindow & Okno);

    int getScore() const;
};


#endif //SNAKE_SNAKE_H
