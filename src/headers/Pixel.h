#pragma once
#include <SFML/Graphics.hpp>

class Pixel
{
    protected:
        sf::RectangleShape square;
        sf::Vector2f position;
    public:
        static const int size=25;
        
        Pixel(int x,int y);
        void draw(sf::RenderWindow &window);
        
};

class HeadPixel:public Pixel
{
    private:
        
    public:
        HeadPixel(int x,int y);
        void draw(sf::RenderWindow &window);
};
