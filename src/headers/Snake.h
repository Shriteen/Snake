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
        enum class Direction{left,right,up,down};
        
        Snake(sf::Color snakeColor,
              sf::Vector2i initPos);
        virtual ~Snake();
        void draw(sf::RenderWindow &window);
        void update(float interval);
        void changeDirection(Direction direction);
        
    private:
        Direction direction;
};
