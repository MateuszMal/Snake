//
// Created by student on 31.08.2020.
//

#include "Controls.h"

Controls::Controls(float width, float height, const sf::Font &font) : Menu(width, height, font) {
    setText();
    setSelectedItem(0);
}

void Controls::setText() {
    text[0].setFont(getFont());
    text[0].setColor(sf::Color::Red);
    text[0].setString("Yellow");
    text[0].setPosition(sf::Vector2f((getWidth() / 2) - 45 ,getHeight() / 4 * 1));

    text[1].setFont(getFont());
    text[1].setColor(sf::Color::White);
    text[1].setString("Red");
    text[1].setPosition(sf::Vector2f((getWidth() / 2) - 38,getHeight() / 4 * 2));

    text[2].setFont(getFont());
    text[2].setColor(sf::Color::White);
    text[2].setString("Back");
    text[2].setPosition(sf::Vector2f((getWidth() / 2) - 35 ,getHeight() / 4 * 3));
}

void Controls::draw(sf::RenderWindow & window) {
    for(const auto & i : text){
        window.draw(i);
    }
}

void Controls::moveUp() {
    if(getSelectedItem() - 1 >= 0){
        text[getSelectedItem()].setFillColor(sf::Color::White);
        //std::cout << "gora" << std::endl;
        setSelectedItem(getSelectedItem()-1);
        text[getSelectedItem()].setFillColor(sf::Color::Red);
    }
}

void Controls::moveDown() {
    if(getSelectedItem() +1 < 3){
        text[getSelectedItem()].setFillColor(sf::Color::White);
        //std::cout << "dol" << std::endl;
        setSelectedItem(getSelectedItem()+1);
        text[getSelectedItem()].setFillColor(sf::Color::Red);
    }
}