#include <boost/test/unit_test.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Settings.h"
#include "gameFunctions.h"

BOOST_AUTO_TEST_SUITE()

    BOOST_AUTO_TEST_CASE(MenuCreateTestCase){
    sf::RenderWindow window;
    Settings settings;
    createWindow(window,settings);\
    Menu menu(settings.getWWidth(),settings.getWHeight(),settings.getFont());
    BOOST_REQUIRE_EQUAL(menu.getSelectedItem(), 0);
    menu.moveDown();
    BOOST_REQUIRE_EQUAL(menu.getSelectedItem(), 1);
    menu.moveDown();
    BOOST_REQUIRE_EQUAL(menu.getSelectedItem(), 2);
    menu.moveUp();
    BOOST_REQUIRE_EQUAL(menu.getSelectedItem(), 1);
    menu.moveUp();
    BOOST_REQUIRE_EQUAL(menu.getSelectedItem(), 0);
    menu.moveUp();
    BOOST_REQUIRE_EQUAL(menu.getSelectedItem(), 0);
}



BOOST_AUTO_TEST_SUITE_END()
