//
// Created by student on 23.08.2020.
//

#include "Options.h"

Options::Options(float width, float height, const sf::Font &font) : Menu(width, height, font){

   }

void Options::draw(sf::RenderWindow & window) {
    for(const auto & i : text){
        window.draw(i);
    }
}

void Options::moveUp() {
    if(getSelectedItem() - 1 >= 0){
        text[getSelectedItem()].setFillColor(sf::Color::White);
        //std::cout << "gora" << std::endl;
        setSelectedItem(getSelectedItem()-1);
        text[getSelectedItem()].setFillColor(sf::Color::Red);
    }
}

void Options::moveDown() {
    if(getSelectedItem() +1 < 3){
        text[getSelectedItem()].setFillColor(sf::Color::White);
        //std::cout << "dol" << std::endl;
        setSelectedItem(getSelectedItem()+1);
        text[getSelectedItem()].setFillColor(sf::Color::Red);
    }
}

void Options::setText() {
    text[0].setFont(getFont());
    text[0].setFillColor(sf::Color::Red);
    text[0].setString("Controls");
    text[0].setPosition(sf::Vector2f((getWidth() / 2) - 65 ,getHeight() / 4 * 1));

    text[1].setFont(getFont());
    text[1].setFillColor(sf::Color::White);
    text[1].setString("Window size");
    text[1].setPosition(sf::Vector2f((getWidth() / 2) - 90,getHeight() / 4 * 2));

    text[2].setFont(getFont());
    text[2].setFillColor(sf::Color::White);
    text[2].setString("Back");
    text[2].setPosition(sf::Vector2f((getWidth() / 2) - 40,getHeight() / 4 * 3));
}
