#ifndef SNAKE_OPTIONS_H
#define SNAKE_OPTIONS_H


#include "Settings.h"
#include "Menu.h"

#define MAX_SELECTED_ITEM 3

class Options : public Menu {
private:
    sf::Text text[3];
public:
    Options(float width, float height, const sf::Font &font);

    void draw(sf::RenderWindow &) override ;

    void moveUp()override ;

    void moveDown() override ;

    void setText() override ;
};


#endif //SNAKE_OPTIONS_H
