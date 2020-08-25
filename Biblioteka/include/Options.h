#ifndef SNAKE_OPTIONS_H
#define SNAKE_OPTIONS_H

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Menu.h"

class Options : public Menu{
private:
    sf::Text text[3];
public:
    Options(float width, float height, const sf::Font &font);
    void draw(sf::RenderWindow &);

    void moveUp();

    void moveDown();
};


#endif //SNAKE_OPTIONS_H
