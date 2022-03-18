#include "headers/Pixel.h"
#include<iostream>
Pixel::Pixel(int x,int y):
    square(sf::Vector2f(Pixel::size,Pixel::size)),
    position(x,y)
{
    
    square.setFillColor(sf::Color::Black);
    
}

void Pixel::draw(sf::RenderWindow &window)
{
    window.draw(square);
}

void Pixel::update()
{
    square.setPosition(sf::Vector2f(position));
}

sf::Vector2i Pixel::getPosition()
{
    return position;
}

sf::FloatRect Pixel::getBounds()
{
    return square.getGlobalBounds();
}

HeadPixel::HeadPixel(int x,int y):
    Pixel(x,y)
{
    
}

void HeadPixel::draw(sf::RenderWindow &window)
{
    Pixel::draw(window);
    
    sf::CircleShape eye(0.12*Pixel::size);
    eye.setPosition(position.x+(Pixel::size*0.38),
                    position.y+(Pixel::size*0.38));
    
    eye.setFillColor(sf::Color::White);
    
    
    window.draw(eye);
}
