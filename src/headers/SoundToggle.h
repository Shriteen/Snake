#pragma once
#include <SFML/Graphics.hpp>

class SoundToggle
{
    private:
        sf::Texture toOff;
        sf::Texture toOn;
        sf::Sprite sprite;
        sf::Color activeColor;
    public:
        SoundToggle(sf::Color activeColor);
        void update(bool soundOn);
        void draw(sf::RenderWindow &window);
        bool isClicked(sf::Event &event,sf::RenderWindow &window);
};
