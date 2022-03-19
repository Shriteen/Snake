#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"

class HUD
{
    private:
        sf::Text scoreText;
        sf::Font font;
        float fontSize;
        sf::Color fontColor;
    public:
        HUD(sf::Color fontColor);
        void update(Snake &snake);
        void draw(sf::RenderWindow &window);
};
