#include "headers/Engine.h"

void Engine::update(float interval)
{
    sf::sleep(sf::milliseconds(1000));
    
    snake.update(interval);
    
}
