#include <iostream>
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
    window.setPosition(sf::Vector2i(200,650));
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

void checkWalls(std::list<Snake> & snake, sf::RenderWindow & window, Settings & settings) {
    //Check collisions with walls
    if(snake.begin()->wallCollision(window)) settings.setState(gameState::MENU);
}

void menuEvents(sf::Event & event, Menu & menu, sf::RenderWindow & window, Settings & settings) {
    //Reactions to events from keyboard in menu
    if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W) menu.moveUp();
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S) menu.moveDown();
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
        switch (menu.getSelectedItem()){
            case 0:
                settings.setState(gameState::PLAY);
//                if(settings.getState() == gameState::PLAY) std::cout << "PLay";
//                else std::cout << "NOOOOO";
                //settings.setMenu(false);
                break;
            case 1:
                settings.setState(gameState::OPTIONS);
                //settings.setOption(true);
                break;
            case 2:
                window.close();
                break;
            default:
                break;
        }
    }
}

void textScores(sf::RenderWindow & window, int & score, sf::Text & text, const sf::Font & font) {
    //Prepare text to draw
    text.setFont(font);
    text.setColor(sf::Color::White);
    text.setString(std::to_string(score));
    text.setPosition(window.getSize().x/2,window.getSize().y - 35);
    text.setCharacterSize(25);
}

void drawScores(sf::RenderWindow & window, sf::Text & text) {
    window.draw(text);
}

void drawSnake(sf::RenderWindow & window, std::list<Snake> & snake) {
    for(auto & s : snake){
        window.draw(s);
    }
}

void optionsEvents(sf::Event & event, Options & options,sf::RenderWindow & window, Settings & settings) {
    //Reactions to events from keyboard in Options
    if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W) options.moveUp();
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S) options.moveDown();
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
        switch (options.getSelectedItem()){
            case 0:
                settings.setState(gameState::OPTIONS);
                break;
            case 1:
                settings.setState(gameState::CONTROLS);
            case 2:
                settings.setState(gameState::MENU);
                break;
        }
    }
}

//void eatSnake(std::list<Snake> & snake, Snake & S) {
//    if(S.getGlobalBounds().intersects(snake.begin()->getGlobalBounds())) std::cout << "AaAAAa\n";
//}

