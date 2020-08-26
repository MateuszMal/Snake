#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include <SFML/Graphics.hpp>
#include "Settings.h"

#define MAX_SELECTED_ITEM 3

class Menu {
private:
    int selectedItem;
    sf::Text text[3];
public:
    Menu(float width, float height, const sf::Font &);
    virtual ~Menu() = default;
    virtual void draw(sf::RenderWindow &window);
    void moveUp();
    virtual void moveDown();

    int getSelectedItem() const;

    void setSelectedItem(int selectedItem);
};


#endif //SNAKE_MENU_H
