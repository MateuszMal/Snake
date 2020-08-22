#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include <SFML/Graphics.hpp>
#include "Settings.h"

class Menu {
private:
    int selectedItem;
    sf::Text text[3];
public:
    Menu(float width, float height, const sf::Font &);
    ~Menu();
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();

    int getSelectedItem() const;
};


#endif //SNAKE_MENU_H
