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
    text[0].setString("Arrows");
    text[0].setPosition(sf::Vector2f((getWidth() / 2) - 55 ,getHeight() / 4 * 1));

    text[1].setFont(getFont());
    text[1].setColor(sf::Color::White);
    text[1].setString("WSAD");
    text[1].setPosition(sf::Vector2f((getWidth() / 2) - 38,getHeight() / 4 * 2));

    text[2].setFont(getFont());
    text[2].setColor(sf::Color::White);
    text[2].setString("Back");
    text[2].setPosition(sf::Vector2f((getWidth() / 2) - 40 ,getHeight() / 4 * 3));
}

void Controls::draw(sf::RenderWindow & window) {
    for(const auto & i : text){
        window.draw(i);
    }
}