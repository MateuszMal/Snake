#include <boost/test/unit_test.hpp>
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "gameFunctions.h"

BOOST_AUTO_TEST_SUITE()
    BOOST_AUTO_TEST_CASE(OPtionsTestCase) {
        sf::RenderWindow window;
        Settings settings;
        createWindow(window, settings);
        Options options(settings.getWWidth(), settings.getWHeight(), settings.getFont());
        BOOST_REQUIRE_EQUAL(options.getSelectedItem(), 0);
        options.moveDown();
        BOOST_REQUIRE_EQUAL(options.getSelectedItem(), 1);
        options.moveDown();
        BOOST_REQUIRE_EQUAL(options.getSelectedItem(), 2);
        options.moveDown();
        BOOST_REQUIRE_EQUAL(options.getSelectedItem(), 2);
        options.moveUp();
        BOOST_REQUIRE_EQUAL(options.getSelectedItem(), 1);
        options.moveUp();
        BOOST_REQUIRE_EQUAL(options.getSelectedItem(), 0);
        options.moveUp();
        BOOST_REQUIRE_EQUAL(options.getSelectedItem(), 0);
    }
BOOST_AUTO_TEST_SUITE_END()