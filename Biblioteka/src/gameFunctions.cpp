#include "gameFunctions.h"


void checkEvents(sf::Event & event, sf::Window & window, sf::Vector2f & vector){
    //Reactions to events from keyboard
    if(event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) vector=sf::Vector2f(0,-20);
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) vector=sf::Vector2f(0,20);
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) vector=sf::Vector2f(-20,0);
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) vector=sf::Vector2f(20,0);
}

void createWindow(sf::Window & window, Settings & settings) {
    window.create(sf::VideoMode(settings.getWWidth(),
                                settings.getWHeight(),
                                settings.getWBitsPerPixel()), "Snake");
    window.setActive(true);
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(settings.getFrameLimit());
    window.setVerticalSyncEnabled(true);
    window.setPosition(sf::Vector2i(10,650));

}
