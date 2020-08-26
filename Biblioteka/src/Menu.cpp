#include "Menu.h"

Menu::Menu(float width, float height, const sf::Font & font) {

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

    setSelectedItem(0);
}

void Menu::draw(sf::RenderWindow &window) {
    for(int i=0; i < MAX_SELECTED_ITEM; i++){
        window.draw(text[i]);
    }
}

//void Menu::moveUp() {
//    if(selectedItem - 1 >= 0){
//        text[selectedItem].setColor(sf::Color::White);
//        selectedItem --;
//        text[selectedItem].setColor(sf::Color::Red);
//    }
//}
//
//void Menu::moveDown() {
//    if(selectedItem + 1 < 3){
//        text[selectedItem].setColor(sf::Color::White);
//        selectedItem ++;
//        text[selectedItem].setColor(sf::Color::Red);
//    }
//}

void Menu::moveUp() {
    if(getSelectedItem() - 1 >= 0){
        text[getSelectedItem()].setColor(sf::Color::White);
        setSelectedItem(getSelectedItem()-1);
        text[getSelectedItem()].setColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if(getSelectedItem() +1 < 3){
        text[getSelectedItem()].setColor(sf::Color::White);
        setSelectedItem(getSelectedItem()+1);
        text[getSelectedItem()].setColor(sf::Color::Red);
    }
}

int Menu::getSelectedItem() const {
    return selectedItem;
}

void Menu::setSelectedItem(int selectedItem) {
    Menu::selectedItem = selectedItem;
}
