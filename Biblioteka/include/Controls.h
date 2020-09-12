//
// Created by student on 31.08.2020.
//

#ifndef SNAKE_CONTROLS_H
#define SNAKE_CONTROLS_H
#define MAX_SELECTED_ITEM 2
#include "Menu.h"

class Controls : public Menu{
private:
    sf::Text text[2];
public:
    Controls(float width, float height, const sf::Font &font);

    virtual ~Controls();

    void setText() override;

};


#endif //SNAKE_CONTROLS_H
