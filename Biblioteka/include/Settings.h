#ifndef SNAKE_SETTINGS_H
#define SNAKE_SETTINGS_H

#include <SFML/Graphics.hpp>

enum class gameState {
    PLAY,
    MENU,
    OPTIONS,
    CONTROLS,
    SCREEN_SIZE
};

class Settings {
    //Window and menu settings
private:
    unsigned int w_height = 640;
    unsigned int w_width = 560;
    unsigned int w_bitsPerPixel = 32;
    unsigned int speed = 200;
    unsigned int frameLimit = 60;
    sf::Font font;

    bool menu = true;

    gameState state = gameState::MENU;
public:

    unsigned int getWHeight() const;

    unsigned int getWWidth() const;

    unsigned int getWBitsPerPixel() const;

    unsigned int getSpeed() const;

    unsigned int getFrameLimit() const;

    void setSpeed(unsigned int speed);

    const sf::Font &getFont();

    bool isMenu() const;

    void setMenu(bool game);

    gameState getState() const;

    void setState(gameState state);

    void setWHeight(unsigned int wHeight);

    void setWWidth(unsigned int wWidth);

};


#endif //SNAKE_SETTINGS_H
