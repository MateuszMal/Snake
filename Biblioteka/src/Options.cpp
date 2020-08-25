//
// Created by student on 23.08.2020.
//

#include "Options.h"

Options::Options(float width, float height, const sf::Font &font) : Menu(width, height, font) {

    text[0].setFont(font);
    text[0].setColor(sf::Color::Red);
    text[0].setString("Controls");
    text[0].setPosition(sf::Vector2f((width  / 2) - 65 ,height / 4 * 1));

    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("Window size");
    text[1].setPosition(sf::Vector2f((width / 2) - 90,height / 4 * 2));

    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString("Back");
    text[2].setPosition(sf::Vector2f((width / 2) - 40,height / 4 * 3));

    setSelectedItem(0);
}

void Options::draw(sf::RenderWindow & window) {
    for(int i=0; i < MAX_SELECTED_ITEM; i++){
        window.draw(text[i]);
    }
}

void Options::moveUp() {
    if(getSelectedItem() - 1 >= 0){
        text[getSelectedItem()].setColor(sf::Color::White);
        setSelectedItem(getSelectedItem()-1);
        text[getSelectedItem()].setColor(sf::Color::Red);
    }
}

void Options::moveDown() {
    if(getSelectedItem() +1 < 3){
        text[getSelectedItem()].setColor(sf::Color::White);
        setSelectedItem(getSelectedItem()+1);
        text[getSelectedItem()].setColor(sf::Color::Red);
    }
}
