#include "headers/FullscreenToggle.h"

FullscreenToggle::FullscreenToggle()
{
    fullscreen.loadFromFile("images/fullscreen.png");
    unfullscreen.loadFromFile("images/unfullscreen.png");
    sprite.setPosition(sf::Vector2f(925,5));
    sprite.setColor(sf::Color(144,144,144));
}

void FullscreenToggle::update(bool full)
{
    if(full)
    {
        sprite.setTexture(unfullscreen);
    }
    else
    {
        sprite.setTexture(fullscreen);
    }
}

void FullscreenToggle::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

bool FullscreenToggle::isClicked(sf::Event &event,sf::RenderWindow &window)
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
