#ifndef SNAKE_OPTIONS_H
#define SNAKE_OPTIONS_H

#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Menu.h"

#define MAX_SELECTED_ITEM 2

class Options : public Menu{
private:
    int selectedItem;
    sf::Text text[MAX_SELECTED_ITEM];
public:
    Options(float width, float height, const sf::Font &font);
};


#endif //SNAKE_OPTIONS_H
