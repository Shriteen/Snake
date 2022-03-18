#include "headers/Snake.h"
#include <iostream>

Snake::Snake(sf::Color snakeColor,
             sf::Vector2i initPos):
    snakeColor(snakeColor),
    direction(Direction::up),
    alive(true)
{
    Pixel *ptr = new Pixel(initPos.x,initPos.y,snakeColor);
    queue.push_front(ptr);
    ptr = new Pixel(initPos.x,initPos.y-Pixel::size,snakeColor);
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
    if(!isAlive())
        return;

    Pixel *ptr;
    sf::Vector2i initPos=queue[0]->getPosition();
    
    switch(direction)
    {
        case Direction::up :
            ptr = new Pixel(initPos.x,initPos.y-Pixel::size,snakeColor);
            break;
        case Direction::down :
            ptr = new Pixel(initPos.x,initPos.y+Pixel::size,snakeColor);
            break;
        case Direction::left :
            ptr = new Pixel(initPos.x-Pixel::size,initPos.y,snakeColor);
            break;    
        case Direction::right :
            ptr = new Pixel(initPos.x+Pixel::size,initPos.y,snakeColor);
            break;
    }
    if(ptr!=nullptr)
    {
        queue.push_front(ptr);
        queue.pop_back();
    }
    
    for(int i=0;i<queue.size();i++)
    {
        queue[i]->update();
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

bool Snake::isAlive()
{
    return alive;
}

sf::FloatRect Snake::getHeadBounds()
{
    return queue[0]->getBounds();
}

void Snake::setAliveStatus(bool status)
{
    this->alive=status;
}

void Snake::operator ++ (int)
{
    Pixel *ptr;
    sf::Vector2i initPos=queue[0]->getPosition();
    
    switch(direction)
    {
        case Direction::up :
            ptr = new Pixel(initPos.x,initPos.y-Pixel::size,snakeColor);
            break;
        case Direction::down :
            ptr = new Pixel(initPos.x,initPos.y+Pixel::size,snakeColor);
            break;
        case Direction::left :
            ptr = new Pixel(initPos.x-Pixel::size,initPos.y,snakeColor);
            break;    
        case Direction::right :
            ptr = new Pixel(initPos.x+Pixel::size,initPos.y,snakeColor);
            break;
    }
    if(ptr!=nullptr)
    {
        queue.push_front(ptr);
        queue[0]->update();
    }
    
}
