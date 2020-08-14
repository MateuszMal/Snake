#ifndef SNAKE_SETTINGS_H
#define SNAKE_SETTINGS_H


class Settings {
private:
    unsigned int w_height = 640;
    unsigned int w_width = 560;
    unsigned int w_bitsPerPixel = 32;
    unsigned int speed = 200;
    unsigned int frameLimit = 60;
public:
    unsigned int getWHeight() const;

    unsigned int getWWidth() const;

    unsigned int getWBitsPerPixel() const;

    unsigned int getSpeed() const;

    unsigned int getFrameLimit() const;

    void setSpeed(unsigned int speed);

};


#endif //SNAKE_SETTINGS_H