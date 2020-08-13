#include "Snake.h"


using namespace sf;

Snake::Snake(int size) :  RectangleShape(Vector2f(size,size)){

    setOrigin(size/2,size/2);
    setFillColor(Color::Green);
    setPosition(rand()%560,rand()%640);
}

Snake::~Snake() {

}

bool Snake::eatFood(sf::CircleShape & C) {
    if(C.getGlobalBounds().intersects(this->getGlobalBounds())) {
        C.setPosition(rand()%560,rand()%640);
        score += 1;
        return true;
    }
    return false;
}

bool Snake::wallColission(sf::RenderWindow & Okno) {
    if(getPosition().x > Okno.getSize().x - getSize().x/2 || getPosition().x <= getSize().x/2
                    || getPosition().y <= getSize().y/2 || getPosition().y > Okno.getSize().y -getSize().y/2){
       setFillColor(Color::Red);
       return true;
    }
    return false;
}

int Snake::getScore() const {
    return score;
}

