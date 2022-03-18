#include "headers/Engine.h"

Engine::Engine():
    window(sf::VideoMode(1080,720),"Snake"),
    bgColor(sf::Color::White),
    borderColor(sf::Color::Black),
    snakeColor(sf::Color::Black),
    foodColor(sf::Color::Red),
    border(sf::Vector2f(1080-(2*Pixel::size),720-(2*Pixel::size))),
    snake(snakeColor,
          sf::Vector2i(1080/2,720/2))
{
    window.setFramerateLimit(60);
    view.reset(sf::FloatRect(0,0,1080,720));
    
    border.setOutlineColor(borderColor);
    border.setOutlineThickness(5);
    border.setPosition(Pixel::size,Pixel::size);
    
    food=new Food(border.getGlobalBounds(),foodColor);
    

}

Engine::~Engine()
{
    delete food;
}

void Engine::start()
{
    sf::Clock clock;
    snake.update(1);
    draw();
    while(window.isOpen())
    {
        input();
        
        sf::Time interval=clock.getElapsedTime();
        
        if(interval.asSeconds() > 0.5)
        {
            update(interval.asSeconds());
            clock.restart();
        }
        
        draw();
    }
}
