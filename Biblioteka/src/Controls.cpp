//
// Created by student on 31.08.2020.
//

#include "Controls.h"

Controls::Controls(float width, float height, const sf::Font &font) : Menu(width, height, font) {
    setText();
    setSelectedItem(0);
}

Controls::~Controls() {

}

void Controls::setText() {
    text[0].setFont(getFont());
    text[0].setColor(sf::Color::Red);
    text[0].setString("Controls");
    text[0].setPosition(sf::Vector2f((getWidth() / 2) - 65 ,getHeight() / 3 * 1));

    text[1].setFont(getFont());
    text[1].setColor(sf::Color::White);
    text[1].setString("Window size");
    text[1].setPosition(sf::Vector2f((getWidth() / 2) - 90,getHeight() / 3 * 2));
}
