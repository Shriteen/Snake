#include "headers/Engine.h"

void Engine::draw()
{
    window.setView(view);
    
    window.clear(bgColor);
        
    snake.draw(window);
    
    
    window.display();
}
