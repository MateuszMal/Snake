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

void snakeMove(std::list<SnakePtr> & snakeList, sf::Time & remainingTime, Settings & settings,
            sf::Vector2f & vector) {
    //Snake's moves. Removes last object from list and add it to front of list
    while(remainingTime > sf::milliseconds(settings.getSpeed())) {
        if (snakeList.size() > 1) {
            snakeList.pop_back();
            // Create SnakePtr and add it at front of list
            SnakePtr snake = std::make_shared<Snake>(20,settings.getSnakeColor());
            // Take first object position
            (*snake).setPosition((*snakeList.begin())->getPosition());
            snakeList.push_front(snake);
        }
        (*snakeList.begin())->move(vector);
        remainingTime -= sf::milliseconds(settings.getSpeed());
    }
}

void collisions(std::list<SnakePtr> & snakeList, FoodPtr & food, sf::Vector2f & vector, Settings & settings) {
    //Check collisions with food
    if ((*snakeList.begin())->eatFood(*food)) {
        SnakePtr snake = std::make_shared<Snake>(20,settings.getSnakeColor());
        (*snake).setPosition(snakeList.back()->getPosition().x - vector.x,
                        snakeList.back()->getPosition().y - vector.y);
        snakeList.push_back(snake);
        settings.setScore(settings.getScore() + 100);
        //Increase snake's speed
        if(settings.getSpeed() > 60) settings.setSpeed(settings.getSpeed() - snakeList.size() * 1.5);
    }
}

void checkWalls(std::list<SnakePtr> & snake, sf::RenderWindow & window, Settings & settings) {
    //Check collisions with walls
    if ((*snake.begin())->wallCollision(window)) settings.setState(gameState::GAME_OVER);
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
    //Prepare score's text to draw
    text.setFont(settings.getFont());
    text.setColor(sf::Color::White);
    text.setString(std::to_string(settings.getScore()));
    text.setPosition(window.getSize().x/2,window.getSize().y - 35);
    text.setCharacterSize(25);
}

void drawScores(sf::RenderWindow & window, sf::Text & text) {
    window.draw(text);
}

void drawSnake(sf::RenderWindow & window, std::list<SnakePtr> & snake) {
    for(auto & s : snake){
        window.draw(*s);
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

void changeColor(sf::Event & event, Menu & menu, sf::RenderWindow & window, Settings & settings, sf::CircleShape & shape) {
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

void changeColor(sf::Event & event, Menu & menu, sf::RenderWindow & window, Settings & settings, sf::RectangleShape & shape) {
    //Reactions to events from keyboard in Controls

    textMoves(event,menu,window);
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return){
        switch (menu.getSelectedItem()){
            case 0:
                settings.setSnakeColor(sf::Color::Yellow);
                settings.setState(gameState::OPTIONS);
                break;
            case 1:
                settings.setSnakeColor(sf::Color::Red);
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

void gameOverEvents(sf::Event & event, sf::RenderWindow & window, Settings & settings,
                    std::list<SnakePtr> & snakeList, SnakePtr & Snake, sf::Vector2f & vector) {
    //Showing game over screen
    if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
        newGame(snakeList,settings,vector,Snake);
        settings.setState(gameState::MENU);
    }

}

void newGame(std::list<SnakePtr> & snakeList, Settings & settings, sf::Vector2f & vector, SnakePtr & snake) {
    //Reset game's achievements
    snake->setPosition(90,90);
    snakeList.clear();
    snakeList.push_back(snake);
    settings.setSpeed(200);
    settings.setScore(0);
    vector = sf::Vector2f(0,0);
}


