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
    bool option = false;
    bool controls = false;

    int chose = 1;

    gameState state = gameState::MENU;
public:

//    Settings(gameState gameState=gameState::MENU);
//
    unsigned int getWHeight() const;

    unsigned int getWWidth() const;

    unsigned int getWBitsPerPixel() const;

    unsigned int getSpeed() const;

    unsigned int getFrameLimit() const;

    void setSpeed(unsigned int speed);

    const sf::Font &getFont();

    bool isMenu() const;

    bool isOption() const;

    void setMenu(bool game);

    void setOption(bool option);

    void setControls(bool controls);

    bool isControls() const;

    int getChose() const;

    gameState getState() const;

    void setState(gameState state);

};


#endif //SNAKE_SETTINGS_H
