//
// Created by student on 31.08.2020.
//

#ifndef SNAKE_CONTROLS_H
#define SNAKE_CONTROLS_H
#define MAX_SELECTED_ITEM 2
#include "Menu.h"

class Controls : public Menu{
private:
    sf::Text text[3];
public:
    Controls(float width, float height, const sf::Font &font);

    void draw(sf::RenderWindow &) override ;

    void moveUp()override ;

    void moveDown() override ;

    void setText() override;


};


#endif //SNAKE_CONTROLS_H
