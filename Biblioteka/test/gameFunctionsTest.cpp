#include <boost/test/unit_test.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"
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
    //Czemu inne wymiary ???
//    BOOST_REQUIRE_EQUAL(window.getPosition().x, 200);
//    BOOST_REQUIRE_EQUAL(window.getPosition().y, 650);
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
    Snake waz(20);
    sf::Time time = sf::milliseconds(201);
    sf::Vector2f vector(20,20);
    std::list<Snake> snake;
    snake.push_back(waz);
    snake.push_back(waz);
    int positionX = snake.begin()->getPosition().x;
    int positionY = snake.begin()->getPosition().y;
    snakeMove(snake,time,settings,waz,vector);
    BOOST_REQUIRE_EQUAL(snake.begin()->getPosition().x, positionX + vector.x);
    BOOST_REQUIRE_EQUAL(snake.begin()->getPosition().y, positionY + vector.y);
}

    BOOST_AUTO_TEST_CASE(CollisionsTestCase){
    int score = 0;
    Settings settings;
    Snake waz(20);
    std::list<Snake> snake;
    snake.push_back(waz);
    FoodPtr food = std::make_shared<Food>(10);
    sf::Vector2f vector(20,20);
    food->setPosition(100,100);
    snake.begin()->setPosition(100,100);
    collisions(snake,food,vector,settings,score,waz);
    BOOST_REQUIRE_EQUAL(snake.size(), 2);
    BOOST_REQUIRE_EQUAL(score, 100);
    BOOST_REQUIRE_EQUAL(settings.getSpeed(), 197);
}

    BOOST_AUTO_TEST_CASE(CheckWallsTestCase){
    Snake waz(20);
    std::list<Snake> snake;
    snake.push_back(waz);
    sf::RenderWindow window;
    Settings settings;
    createWindow(window,settings);
    snake.begin()->setPosition(0,0);
    checkWalls(snake,window,settings);
    BOOST_REQUIRE_EQUAL(settings.isMenu(), true);
    snake.begin()->setPosition(50,50);
    settings.setMenu(false);
    checkWalls(snake,window,settings);
    BOOST_REQUIRE_EQUAL(settings.isMenu(), false);
}


BOOST_AUTO_TEST_SUITE_END()