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
    font.loadFromFile(s);
    return font;
}

