#include <boost/test/unit_test.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <../include/Snake.h>
#include "../include/Food.h"


BOOST_AUTO_TEST_SUITE(SnakeSuiteCorrect)

    BOOST_AUTO_TEST_CASE(SnakeTestCase) {
        sf::RenderWindow Okno;
        Okno.create(sf::VideoMode(560, 640, 32), "Okno");
        Snake waz(20);
        BOOST_REQUIRE_EQUAL(waz.getSize1(), 20);
    }
    BOOST_AUTO_TEST_CASE(SnakeCollisionTestCase) {
        sf::RenderWindow Okno;
        Okno.create(sf::VideoMode(560, 640, 32), "Okno");
        Snake waz(20);
        waz.setPosition(560, 640);
        BOOST_REQUIRE_EQUAL(waz.wallCollision(Okno), true);
        FoodPtr jablko = std::make_shared<Food>(10);
        jablko->setPosition(100,100);
        waz.setPosition(100,100);
        BOOST_REQUIRE_EQUAL(waz.eatFood(*jablko), true);
        }


BOOST_AUTO_TEST_SUITE_END()