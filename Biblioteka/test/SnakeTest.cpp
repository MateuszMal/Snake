#include <boost/test/unit_test.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <../include/Snake.h>


BOOST_AUTO_TEST_SUITE(SnakeSuiteCorrect)

BOOST_AUTO_TEST_CASE(SnakeTestCase){
    sf::RenderWindow *Okno;
    Snake waz(20);
    BOOST_REQUIRE_EQUAL(waz.getLength(), 1);
}

BOOST_AUTO_TEST_SUITE_END()