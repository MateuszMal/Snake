#include "Snake.h"


using namespace sf;

Snake::Snake(unsigned int size) :  size(size), RectangleShape(Vector2f(size,size)){

    setOrigin((float)size/2,(float)size/2);
    setFillColor(Color::Green);
    setPosition(90,90);
}

bool Snake::eatFood(sf::CircleShape & C) {
    if(C.getGlobalBounds().intersects(getGlobalBounds())) {
        C.setPosition(rand()%560,rand()%640);
        return true;
    }
    return false;
}
//Zmienic na snake.begin().getPosition().x
bool Snake::wallCollision(sf::RenderWindow & Okno) {
    return this->getPosition().x >= Okno.getSize().x || this->getPosition().x <= 0
           || this->getPosition().y <= 0 || this->getPosition().y >= Okno.getSize().y;
}

bool Snake::eatYourself(Snake & S) {
    return S.getGlobalBounds().intersects(getGlobalBounds());
}

unsigned int Snake::getSize1() const {
    return size;
}



