#pragma once
#include <SFML/Graphics.hpp>

class Pixel
{
    protected:
        sf::RectangleShape square;
        sf::Vector2i position;
        sf::Color color;
    public:
        static const int size=25;
        
        Pixel(int x=0,int y=0,sf::Color color=sf::Color::Black);
        void draw(sf::RenderWindow &window);
        void update();
        sf::Vector2i getPosition();
        sf::FloatRect getBounds();
        
};

class HeadPixel:public Pixel
{
    private:
        
    public:
        HeadPixel(int x,int y,sf::Color color);
        void draw(sf::RenderWindow &window);
};
