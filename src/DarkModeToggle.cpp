#include "headers/DarkModeToggle.h"

DarkModeToggle::DarkModeToggle()
{
    toLight.loadFromFile("images/to_light.png");
    toDark.loadFromFile("images/to_dark.png");
    sprite.setPosition(sf::Vector2f(25,25));
}

void DarkModeToggle::update(colorScheme scheme)
{
    if(scheme == colorScheme::light)
        sprite.setTexture(toDark);
    else if(scheme == colorScheme::dark)
        sprite.setTexture(toLight);
}

void DarkModeToggle::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

bool DarkModeToggle::isClicked(sf::Event &event,sf::RenderWindow &window)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        int x = event.mouseButton.x;
        int y = event.mouseButton.y;
    
        if(sprite.getGlobalBounds().contains( window.mapPixelToCoords(sf::Vector2i(x,y) ) ))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
