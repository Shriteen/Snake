#pragma once
#include <SFML/Graphics.hpp>

class FullscreenToggle
{
    private:
        sf::Texture fullscreen;
        sf::Texture unfullscreen;
        sf::Sprite sprite;
    public:
        FullscreenToggle();
        void update(bool full);
        void draw(sf::RenderWindow &window);
        bool isClicked(sf::Event &event,sf::RenderWindow &window);
};
