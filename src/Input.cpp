#include "headers/Engine.h"

void Engine::input()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed :
                window.close();
                break;
            
            case sf::Event::Resized :
                adjustViews(event.size.width,event.size.height);
                break;
            
            case sf::Event::KeyReleased :
                if(snake->isAlive() && playing)
                {
                    if(event.key.code == sf::Keyboard::Up ||
                       event.key.code == sf::Keyboard::W)
                    {
                        snake->changeDirection(Snake::Direction::up);
                    }
                    else if(event.key.code == sf::Keyboard::Down ||
                            event.key.code == sf::Keyboard::S)
                    {
                        snake->changeDirection(Snake::Direction::down);
                    }
                    else if(event.key.code == sf::Keyboard::Left ||
                            event.key.code == sf::Keyboard::A)
                    {
                        snake->changeDirection(Snake::Direction::left);
                    }
                    else if(event.key.code == sf::Keyboard::Right ||
                            event.key.code == sf::Keyboard::D)
                    {
                        snake->changeDirection(Snake::Direction::right);
                    }
                }
                break;
                
            case sf::Event::KeyPressed :
                if(event.key.code == sf::Keyboard::Space ||
                   event.key.code == sf::Keyboard::Escape )
                {
                    playing=!playing;
                }
                break;
            
            case sf::Event::MouseButtonPressed :
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;
                if(hud.getPauseOrPlayButtonBounds().contains( window.mapPixelToCoords(sf::Vector2i(x,y),hudView ) ))
                {
                    playing=!playing;
                }
                break;
                
        }
    }
    
    
    
}
