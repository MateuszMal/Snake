#include <boost/test/unit_test.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Settings.h"
#include "gameFunctions.h"
#include "Food.h"


BOOST_AUTO_TEST_SUITE()

    BOOST_AUTO_TEST_CASE(CreateWindowTestCase){
    sf::RenderWindow window;
    Settings settings;
    createWindow(window, settings);
    BOOST_REQUIRE_EQUAL(window.getSize().x, settings.getWWidth());
    BOOST_REQUIRE_EQUAL(window.getSize().y, settings.getWHeight());
    BOOST_REQUIRE_EQUAL(window.setActive(), true);
}

    BOOST_AUTO_TEST_CASE(checkEventsTestCase){
    sf::RenderWindow window;
    Settings settings;
    createWindow(window, settings);
    sf::Event event;
    event.key.code = sf::Keyboard::W;
    event.KeyPressed;
    BOOST_REQUIRE_EQUAL(window.pollEvent(event), true);
}

    BOOST_AUTO_TEST_CASE(SnakeMoveTestCase){
    Settings  settings;
    SnakePtr waz = std::make_shared<Snake>(20);
    sf::Time time = sf::milliseconds(201);
    sf::Vector2f vector(20,20);
    std::list<SnakePtr> snake;
    snake.push_back(waz);
    snake.push_back(waz);
    int positionX = (*snake.begin())->getPosition().x;
    int positionY = (*snake.begin())->getPosition().y;
    snakeMove(snake,time,settings,vector);
    BOOST_REQUIRE_EQUAL((*snake.begin())->getPosition().x, positionX + vector.x);
    BOOST_REQUIRE_EQUAL((*snake.begin())->getPosition().y, positionY + vector.y);
}

    BOOST_AUTO_TEST_CASE(CollisionsTestCase){
//    int score = 0;
    Settings settings;
    SnakePtr waz = std::make_shared<Snake>(20);
    std::list<SnakePtr> snake;
    snake.push_back(waz);
    FoodPtr food = std::make_shared<Food>(10);
    sf::Vector2f vector(20,20);
    food->setPosition(100,100);
    (*snake.begin())->setPosition(100,100);
    collisions(snake,food,vector,settings);
    BOOST_REQUIRE_EQUAL(snake.size(), 2);
    BOOST_REQUIRE_EQUAL(settings.getScore(), 100);
    BOOST_REQUIRE_EQUAL(settings.getSpeed(), 197);
}

    BOOST_AUTO_TEST_CASE(CheckWallsTestCase){
    SnakePtr waz = std::make_shared<Snake>(20);
    std::list<SnakePtr> snake;
    snake.push_back(waz);
    sf::RenderWindow window;
    Settings settings;
    createWindow(window,settings);
    (*snake.begin())->setPosition(0,0);
    checkWalls(snake,window,settings);
    BOOST_CHECK(settings.getState() == gameState::GAME_OVER);
    (*snake.begin())->setPosition(50,50);
    settings.setState(gameState::PLAY);
    checkWalls(snake,window,settings);
    BOOST_CHECK(settings.getState() ==gameState::PLAY);
}


BOOST_AUTO_TEST_SUITE_END()