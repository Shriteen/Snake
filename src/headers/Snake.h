#pragma once
#include <SFML/Graphics.hpp>
#include <deque>
#include "Pixel.h"

class Snake
{
    private:
        sf::Color snakeColor;
        std::deque<Pixel*> queue;
    public:
        Snake(sf::Color snakeColor,
              sf::Vector2i initPos);
        virtual ~Snake();
        void draw(sf::RenderWindow &window);
};
