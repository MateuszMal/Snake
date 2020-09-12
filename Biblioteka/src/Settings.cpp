#include "Settings.h"

unsigned int Settings::getWHeight() const {
    return w_height;
}

unsigned int Settings::getWWidth() const {
    return w_width;
}

unsigned int Settings::getWBitsPerPixel() const {
    return w_bitsPerPixel;
}

unsigned int Settings::getSpeed() const {
    return speed;
}

unsigned int Settings::getFrameLimit() const {
    return frameLimit;
}

void Settings::setSpeed(unsigned int speed) {
    Settings::speed = speed;
}

const sf::Font &Settings::getFont() {
    std::string s = "../../font/OpenSans-Bold.ttf";
    if(!font.loadFromFile(s)){
//        //Zlapac wyjatek
    }
    return font;
}

bool Settings::isMenu() const {
    return menu;
}

bool Settings::isOption() const {
    return option;
}

void Settings::setMenu(bool game) {
    Settings::menu = game;
}

void Settings::setOption(bool option) {
    Settings::option = option;
}

void Settings::setControls(bool controls) {
    Settings::controls = controls;
}

bool Settings::isControls() const {
    return controls;
}

int Settings::getChose() const {
    return chose;
}

gameState Settings::getState() const {
    return state;
}

void Settings::setState(gameState state) {
    Settings::state = state;
}

//Settings::Settings(gameState gameState){}

