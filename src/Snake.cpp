#include "headers/Snake.h"

Snake::Snake(sf::Color snakeColor,
             sf::Vector2i initPos):
    snakeColor(snakeColor)
{
    Pixel *ptr = new Pixel(initPos.x,initPos.y);
    queue.push_front(ptr);
    ptr = new Pixel(initPos.x,initPos.y-Pixel::size);
    queue.push_front(ptr);
}

Snake::~Snake()
{
    while(!queue.empty())
    {
        delete queue.front();
        queue.pop_front();
    }
}

void Snake::draw(sf::RenderWindow &window)
{
    ((HeadPixel*) queue[0] )->draw(window);
    
    for(int i=1;i<queue.size();i++)
    {
        queue[i]->draw(window);
    }
}
