#include "headers/Pixel.h"
#include<iostream>
Pixel::Pixel(int x,int y,sf::Color color):
    square(sf::Vector2f(Pixel::size,Pixel::size)),
    position(x,y),
    color(color)
{
    
}

void Pixel::draw(sf::RenderWindow &window)
{
    window.draw(square);
}

void Pixel::update()
{
    square.setPosition(sf::Vector2f(position));
    square.setFillColor(color);
}

sf::Vector2i Pixel::getPosition()
{
    return position;
}

sf::FloatRect Pixel::getBounds()
{
    return square.getGlobalBounds();
}

HeadPixel::HeadPixel(int x,int y,sf::Color color):
    Pixel(x,y,color)
{
    
}

void HeadPixel::draw(sf::RenderWindow &window)
{
    Pixel::draw(window);
    
    sf::CircleShape eye(0.12*Pixel::size);
    eye.setPosition(position.x+(Pixel::size*0.38),
                    position.y+(Pixel::size*0.38));
    
    if(color == sf::Color::White)
        eye.setFillColor(sf::Color::Black);
    else if(color == sf::Color::Black)
        eye.setFillColor(sf::Color::White);
    
    window.draw(eye);
}
