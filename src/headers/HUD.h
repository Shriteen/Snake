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
        sf::Texture pauseTexture;
        sf::Texture playTexture;
        sf::Sprite pauseOrPlayButton;
    public:
        HUD(sf::Color fontColor);
        void update(Snake &snake,bool playing);
        void draw(sf::RenderWindow &window);
        sf::FloatRect getPauseOrPlayButtonBounds();
};
