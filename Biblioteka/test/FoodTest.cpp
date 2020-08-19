#include <boost/test/unit_test.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Food.h"

BOOST_AUTO_TEST_SUITE(FoodSuiteCorrect)

    BOOST_AUTO_TEST_CASE(FoodTestCase){
    Food food(10);
    BOOST_REQUIRE_EQUAL(food.getOrigin().x, 5);
    BOOST_REQUIRE_EQUAL(food.getOrigin().y, 5);
}

BOOST_AUTO_TEST_SUITE_END()