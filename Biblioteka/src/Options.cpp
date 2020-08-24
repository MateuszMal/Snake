//
// Created by student on 23.08.2020.
//

#include "Options.h"

Options::Options(float width, float height, const sf::Font &font) : Menu(width, height, font) {
    text[0].setFont(font);
    text[0].setColor(sf::Color::Red);
    text[0].setString("Sterowanie");
    text[0].setPosition(sf::Vector2f((width  / 2) - 20 ,height / 4 * 1));

    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("Rozmiar okna");
    text[1].setPosition(sf::Vector2f((width / 2) - 50,height / 4 * 2));
}
