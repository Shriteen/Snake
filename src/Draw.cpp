#include "headers/Engine.h"

void Engine::draw()
{
    window.setView(view);
    
    window.clear(bgColor);
    
    window.draw(border);    
    snake.draw(window);
    
    window.display();
}
