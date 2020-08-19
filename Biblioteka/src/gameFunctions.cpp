#include "gameFunctions.h"


void checkEvents(sf::Event & event, sf::RenderWindow & window, sf::Vector2f & vector){
    //Reactions to events from keyboard
    if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) vector=sf::Vector2f(0,-20);
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) vector=sf::Vector2f(0,20);
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) vector=sf::Vector2f(-20,0);
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) vector=sf::Vector2f(20,0);
}

void createWindow(sf::RenderWindow & window, Settings & settings) {
    //creating window
    window.create(sf::VideoMode(settings.getWWidth(),
                                settings.getWHeight(),
                                settings.getWBitsPerPixel()), "Snake");
    window.setActive(true);
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(settings.getFrameLimit());
    window.setVerticalSyncEnabled(true);
    window.setPosition(sf::Vector2i(10,650));

}

void snakeMove(std::list<Snake> & snake, sf::Time & remainingTime, Settings & settings, Snake & S, sf::Vector2f & vector) {
    //Snake's moves
    while(remainingTime > sf::milliseconds(settings.getSpeed())) {

        if (snake.size() > 1) {
            snake.pop_back();
            S.setPosition(snake.begin()->getPosition());
            snake.push_front(S);
        }
        snake.begin()->move(vector);

        remainingTime -= sf::milliseconds(settings.getSpeed());
    }
}

void collisions(std::list<Snake> & snake, FoodPtr & food, sf::Vector2f & vector, Settings & settings, int & score, Snake & S) {
    //Check collisions with food
    if (snake.begin()->eatFood(*food)) {
        S.setPosition(snake.back().getPosition().x - vector.x,
                        snake.back().getPosition().y - vector.y);
        snake.push_back(S);
        score += 100;
        //Increase snake's speed
        if(settings.getSpeed() > 60) settings.setSpeed(settings.getSpeed() - snake.size() * 1.5);
    }
}

void checkWalls(std::list<Snake> & snake, sf::RenderWindow & window, bool & game) {
    for(auto & s : snake){
        if(s.wallCollision(window)) game = false;
        window.draw(s);
    }
}
