#include "headers/Snake.h"

Snake::Snake(sf::Color snakeColor,
             sf::Vector2i initPos):
    snakeColor(snakeColor),
    direction(Direction::up)
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

void Snake::update(float interval)
{
    Pixel *ptr;
    sf::Vector2i initPos=queue[0]->getPosition();
    
    switch(direction)
    {
        case Direction::up :
            ptr = new Pixel(initPos.x,initPos.y-Pixel::size);
            break;
        case Direction::down :
            ptr = new Pixel(initPos.x,initPos.y+Pixel::size);
            break;
        case Direction::left :
            ptr = new Pixel(initPos.x-Pixel::size,initPos.y);
            break;    
        case Direction::right :
            ptr = new Pixel(initPos.x+Pixel::size,initPos.y);
            break;
    }
    if(ptr!=nullptr)
    {
        queue.push_front(ptr);
        queue.pop_back();
    }
    
}

void Snake::changeDirection(Direction direction)
{
    if((this->direction==Direction::up && direction==Direction::down) ||
       (this->direction==Direction::down && direction==Direction::up) ||
       (this->direction==Direction::left && direction==Direction::right) ||
       (this->direction==Direction::right && direction==Direction::left) )
            return;
    this->direction=direction;
}
