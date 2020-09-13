//
// Created by student on 29.07.2020.
//

#include "../include/Food.h"

using namespace sf;

Food::Food(float size) : CircleShape(size){
    this->setFillColor(Color::Red);
    this->setOrigin(size/2,size/2);
    this->setPosition(rand()%560 - size*2,rand()%640 - size*2);
}

bool Food::isColision(std::list<sf::RectangleShape> &waz) {
    for(auto & r : waz){
        if(r.getGlobalBounds().intersects(getGlobalBounds())) return true;
    }
    return false;
}
