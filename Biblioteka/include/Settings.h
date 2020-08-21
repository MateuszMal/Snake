#ifndef SNAKE_SETTINGS_H
#define SNAKE_SETTINGS_H

#include <SFML/Graphics.hpp>

class Settings {
    //Window and game settings
private:
    unsigned int w_height = 640;
    unsigned int w_width = 560;
    unsigned int w_bitsPerPixel = 32;
    unsigned int speed = 200;
    unsigned int frameLimit = 60;
    sf::Font font;

public:
    unsigned int getWHeight() const;

    unsigned int getWWidth() const;

    unsigned int getWBitsPerPixel() const;

    unsigned int getSpeed() const;

    unsigned int getFrameLimit() const;

    void setSpeed(unsigned int speed);
    const sf::Font &getFont();

};


#endif //SNAKE_SETTINGS_H
