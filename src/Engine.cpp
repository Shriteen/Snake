#include "headers/Engine.h"

Engine::Engine():
    window(sf::VideoMode(1080,720),"Snake"),
	bgColor(sf::Color::White),
	snakeColor(sf::Color::Black),
    snake(snakeColor,
          sf::Vector2i(1080/2,720/2))
{
	window.setFramerateLimit(60);
    view.reset(sf::FloatRect(0,0,1080,720));

}

void Engine::start()
{
    sf::Clock clock;
	while(window.isOpen())
    {
        sf::Time interval=clock.restart();
        
        input();
        update(interval.asSeconds());
        draw();
    }
}
