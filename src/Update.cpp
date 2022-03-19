#include "headers/Engine.h"
#include <iostream>

void Engine::update(float interval)
{   
    if(playing)
    {
        snake.update(interval);
    
        sf::FloatRect headHitBox=snake.getHeadBounds();
        if( !(border.getGlobalBounds().contains( headHitBox.left , headHitBox.top ) &&
              border.getGlobalBounds().contains( headHitBox.left+headHitBox.width , headHitBox.top ) &&
              border.getGlobalBounds().contains( headHitBox.left , headHitBox.top+headHitBox.height ) &&
              border.getGlobalBounds().contains( headHitBox.left+headHitBox.width , headHitBox.top+headHitBox.height )) )
        {
            snake.setAliveStatus(false);
        }
        
        if( food->getBounds().intersects(snake.getHeadBounds()) )
        {
            delete food;
            food =new Food(border.getGlobalBounds(),foodColor);
            snake++;
        }
        food->update();
    }    
    hud.update(snake,playing);
}
