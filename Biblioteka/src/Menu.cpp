#include "Menu.h"

Menu::Menu(float width, float height, Settings & settings) {
    if(!font.loadFromFile("../../font/OpenSans-Bold.ttf")){
//        //Zlapac wyjatek
    }
    text[0].setFont(font);
    text[0].setColor(sf::Color::Red);
    text[0].setString("Play");
    text[0].setPosition(sf::Vector2f((width  / 2) - 20 ,height / 4 * 1));

    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("Options");
    text[1].setPosition(sf::Vector2f((width / 2) - 50,height / 4 * 2));

    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString("Quit");
    text[2].setPosition(sf::Vector2f((width / 2) - 20,height / 4 * 3));

    selectedItem = 0;
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window) {
    for(int i=0; i < 3; i++){
        window.draw(text[i]);
    }
}

void Menu::moveUp() {
    if(selectedItem - 1 >= 0){
        text[selectedItem].setColor(sf::Color::White);
        selectedItem --;
        text[selectedItem].setColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if(selectedItem + 1 < 3){
        text[selectedItem].setColor(sf::Color::White);
        selectedItem ++;
        text[selectedItem].setColor(sf::Color::Red);
    }
}

int Menu::getSelectedItem() const {
    return selectedItem;
}
