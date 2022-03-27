#include "headers/SoundToggle.h"

SoundToggle::SoundToggle(sf::Color activeColor)
{
    toOff.loadFromFile("images/to_sound_off.png");
    toOn.loadFromFile("images/to_sound_on.png");
    sprite.setPosition(sf::Vector2f(1005,25));
    
    this->activeColor=activeColor;
}

void SoundToggle::update(bool soundOn)
{
    if(soundOn)
    {
        sprite.setTexture(toOff);
        sprite.setColor(activeColor);
    }
    else
    {
        sprite.setTexture(toOn);
        sprite.setColor(sf::Color(127,127,127));
    }
}

void SoundToggle::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

bool SoundToggle::isClicked(sf::Event &event,sf::RenderWindow &window)
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
