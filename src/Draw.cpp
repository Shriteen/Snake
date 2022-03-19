#include "headers/Engine.h"

void Engine::draw()
{
    window.setView(view);
    
    window.clear(bgColor);
    
    window.draw(border);
    food->draw(window);
    snake.draw(window);
    hud.draw(window);
    
    
    window.display();
}
