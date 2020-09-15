#include "Settings.h"

float Settings::getWHeight() const {
    return w_height;
}

float Settings::getWWidth() const {
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

void Settings::setSpeed(unsigned int _speed) {
    Settings::speed = _speed;
}

const sf::Font &Settings::getFont() {
    std::string s = "../../font/OpenSans-Bold.ttf";
    if(!font.loadFromFile(s)){
//        //Zlapac wyjatek
    }
    return font;
}

gameState Settings::getState() const {
    return state;
}

void Settings::setState(gameState state) {
    Settings::state = state;
}

int Settings::getScore() const {
    return score;
}

void Settings::setScore(int score) {
    Settings::score = score;
}

sf::Color &Settings::getSnakeColor(){
    return snakeColor;
}

void Settings::setSnakeColor(const sf::Color &snakeColor) {
    Settings::snakeColor = snakeColor;
}


