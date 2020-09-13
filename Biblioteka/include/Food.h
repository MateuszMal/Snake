//
// Created by student on 29.07.2020.
//

#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

class Food : public sf::CircleShape{
public:
    Food(float size);
    ~Food() = default;
    //Czy potrzebne??
    bool isColision(std::list<sf::RectangleShape> & waz);
};

typedef std::shared_ptr<Food> FoodPtr;
#endif //SNAKE_FOOD_H
