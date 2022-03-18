#pragma once
#include <SFML/Graphics.hpp>

class Pixel
{
    protected:
        sf::RectangleShape square;
        sf::Vector2i position;
    public:
        static const int size=25;
        
        Pixel(int x,int y);
        void draw(sf::RenderWindow &window);
        void update();
        sf::Vector2i getPosition();
        sf::FloatRect getBounds();
        
};

class HeadPixel:public Pixel
{
    private:
        
    public:
        HeadPixel(int x,int y);
        void draw(sf::RenderWindow &window);
};
