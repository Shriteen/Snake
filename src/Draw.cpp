#include "headers/Engine.h"

void Engine::draw()
{
    window.setView(view);
    
    window.clear(bgColor);
    
    window.draw(border);
    food->draw(window);
    snake->draw(window);
    
    
    window.setView(hudView);
    hud.draw(window);
    
    if(!playing)
    {
        window.setView(view);
        pauseMenu.draw(window);
    }
    
    window.display();
}
