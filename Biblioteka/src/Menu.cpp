#include <iostream>
#include "Menu.h"

Menu::Menu(float width, float height, const sf::Font & font) : width(width), height(height), font(font),
                                                               selectedItem(0){

}

void Menu::draw(sf::RenderWindow &window) {
    for(const auto & i : text){
        window.draw(i);
    }
}

void Menu::moveUp() {
    if(getSelectedItem() - 1 >= 0){
        text[getSelectedItem()].setFillColor(sf::Color::White);
        //std::cout << "gora" << std::endl;
        setSelectedItem(getSelectedItem()-1);
        text[getSelectedItem()].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if(getSelectedItem() +1 < 3){
        text[getSelectedItem()].setFillColor(sf::Color::White);
        //std::cout << "dol" << std::endl;
        setSelectedItem(getSelectedItem()+1);
        text[getSelectedItem()].setFillColor(sf::Color::Red);
    }
}

int Menu::getSelectedItem() const {
    return selectedItem;
}

void Menu::setSelectedItem(int _selectedItem) {
    selectedItem = _selectedItem;
}

void Menu::setText() {
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::Red);
    text[0].setString("Play");
    text[0].setPosition(sf::Vector2f((width  / 2) - 20 ,height / 4 * 1));

    text[1].setFont(font);
    text[1].setFillColor(sf::Color::White);
    text[1].setString("Options");
    text[1].setPosition(sf::Vector2f((width / 2) - 50,height / 4 * 2));

    text[2].setFont(font);
    text[2].setFillColor(sf::Color::White);
    text[2].setString("Quit");
    text[2].setPosition(sf::Vector2f((width / 2) - 20,height / 4 * 3));
}

const sf::Font &Menu::getFont() const {
    return font;
}

float Menu::getWidth() const {
    return width;
}

float Menu::getHeight() const {
    return height;
}
