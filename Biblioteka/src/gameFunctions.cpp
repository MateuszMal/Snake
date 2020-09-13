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

void collisions(std::list<Snake> & snake, FoodPtr & food, sf::Vector2f & vector, Settings & settings, Snake & S) {
    //Check collisions with food
    if (snake.begin()->eatFood(*food)) {
        S.setPosition(snake.back().getPosition().x - vector.x,
                        snake.back().getPosition().y - vector.y);
        snake.push_back(S);
        int score = settings.getScore() + 100;
        settings.setScore(score);
        //Increase snake's speed
        if(settings.getSpeed() > 60) settings.setSpeed(settings.getSpeed() - snake.size() * 1.5);
    }
}

void checkWalls(std::list<Snake> & snake, sf::RenderWindow & window, Settings & settings) {
    //Check collisions with walls
    if (snake.begin()->wallCollision(window)) settings.setState(gameState::GAME_OVER);
}

void menuEvents(sf::Event & event, Menu & menu, sf::RenderWindow & window, Settings & settings) {
    textMoves(event,menu,window);
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
        switch (menu.getSelectedItem()){
            case 0:
                settings.setState(gameState::PLAY);

                break;
            case 1:
                settings.setState(gameState::OPTIONS);
                break;
            case 2:
                window.close();
                break;
            default:
                break;
        }
    }
}

void textScores(sf::RenderWindow & window, Settings & settings, sf::Text & text) {
    //Prepare text to draw
    text.setFont(settings.getFont());
    text.setColor(sf::Color::White);
    text.setString(std::to_string(settings.getScore()));
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

    textMoves(event,options,window);
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
        switch (options.getSelectedItem()){
            case 0:
                settings.setState(gameState::FRUIT_COLOR);
                break;
            case 1:
                settings.setState(gameState::SNAKE_COLOR);
                break;
            case 2:
                settings.setState(gameState::MENU);
                break;
        }
    }
}

void changeColor(sf::Event & event, Menu & menu, sf::RenderWindow & window, Settings & settings, sf::Shape & shape) {
    //Reactions to events from keyboard in Controls

    textMoves(event,menu,window);
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
        switch (menu.getSelectedItem()){
            case 0:
                shape.setFillColor(sf::Color::Yellow);
                settings.setState(gameState::OPTIONS);
                break;
            case 1:
                shape.setFillColor(sf::Color::Red);
                settings.setState(gameState::OPTIONS);
                break;
            case 2:
                settings.setState(gameState::OPTIONS);
                break;
        }
    }
}

void textMoves(sf::Event & event, Menu & menu, sf::RenderWindow & window) {
    //Check keyboard events
    if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W) menu.moveUp();
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S) menu.moveDown();
}

void gameOver(sf::RenderWindow & window, Settings & settings) {
    window.clear();
    sf::Text text;
    text.setFont(settings.getFont());
    text.setFillColor(sf::Color::Red);
    text.setString("GAME OVER");
    text.setPosition(window.getSize().x / 2 - 80, window.getSize().y / 4 * 1);
    window.draw(text);

    sf::Text text2;
    text2.setFont(settings.getFont());
    text2.setFillColor(sf::Color::White);
    std::string wynik = std::to_string(settings.getScore());
    text2.setString("Your Score: " + wynik);
    text2.setPosition(window.getSize().x / 2 - 105, window.getSize().y / 4 * 2);
    window.draw(text2);

    sf::Text text3;
    text3.setFont(settings.getFont());
    text3.setFillColor(sf::Color::White);
    text3.setString("Press Enter");
    text3.setPosition(window.getSize().x / 2 - 75, window.getSize().y / 4 * 3);
    window.draw(text3);

}

void gameOverEvents(sf::Event & event, sf::RenderWindow & window) {
    //Showing game over screen
    if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)
    || sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) window.close();
}


