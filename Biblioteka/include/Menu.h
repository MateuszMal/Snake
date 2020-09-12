#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include <SFML/Graphics.hpp>
#include "Settings.h"

#define MAX_SELECTED_ITEM 3

class Menu {
private:
    int selectedItem;
    sf::Text text[3];
    sf::Font font;
    float width, height;
public:
    Menu(float width, float height, const sf::Font &);
    virtual ~Menu() = default;
    virtual void draw(sf::RenderWindow &window);

    virtual void moveUp();

    virtual void moveDown();

    virtual void setText();

    int getSelectedItem() const;

    void setSelectedItem(int selectedItem);

    const sf::Font &getFont() const;

    float getWidth() const;

    float getHeight() const;
};


#endif //SNAKE_MENU_H
