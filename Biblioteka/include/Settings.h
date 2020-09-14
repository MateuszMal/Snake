#ifndef SNAKE_SETTINGS_H
#define SNAKE_SETTINGS_H

#include <SFML/Graphics.hpp>

enum class gameState {
    PLAY,
    MENU,
    OPTIONS,
    FRUIT_COLOR,
    SNAKE_COLOR,
    GAME_OVER
};

class Settings {
    //Window and menu settings
private:
    float w_height = 640;
    float w_width = 560;
    unsigned int w_bitsPerPixel = 32;
    unsigned int speed = 200;
    unsigned int frameLimit = 60;
    sf::Font font;
    int score = 0;
    gameState state = gameState::MENU;
public:
    void setScore(int score);

    int getScore() const;

    float getWHeight() const;

    float getWWidth() const;

    unsigned int getWBitsPerPixel() const;

    unsigned int getSpeed() const;

    unsigned int getFrameLimit() const;

    void setSpeed(unsigned int _speed);

    const sf::Font &getFont();

    gameState getState() const;

    void setState(gameState state);

    };


#endif //SNAKE_SETTINGS_H
