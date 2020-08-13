#include "Snake.h"


using namespace sf;

Snake::Snake(int size) :  RectangleShape(Vector2f(size,size)){

    setOrigin(size/2,size/2);
    setFillColor(Color::Green);
    setPosition(90,90);
}

Snake::~Snake() {

}

bool Snake::eatFood(sf::CircleShape & C) {
    if(C.getGlobalBounds().intersects(getGlobalBounds())) {
        C.setPosition(rand()%560,rand()%640);
        return true;
    }
    return false;
}

bool Snake::wallColission(sf::RenderWindow & Okno) {
    if(getPosition().x >= Okno.getSize().x || getPosition().x <= 0
                    || getPosition().y <= 0 || getPosition().y >= Okno.getSize().y){
       setFillColor(Color::Red);
       return true;
    }
    return false;
}

bool Snake::eatYourself(Snake & S) {
    if(S.getGlobalBounds().intersects(getGlobalBounds())) return true;
    return false;
}



