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
                if(float(event.size.width)/float(event.size.height) > 1.5 )
                {
                    view.setViewport(sf::FloatRect( 0.5-(float(event.size.height*1.25)/float(2000)),
                                     0.1,
                                     ((event.size.height*1.25)/float(1000)),
                                     0.9));
                    hudView.setViewport(sf::FloatRect( 0.5-(float(event.size.height*1.25)/float(2000)),
                                     0,
                                     ((event.size.height*1.25)/float(1000)),
                                     0.1));
                }
                else
                {
                    view.setViewport(sf::FloatRect(0,
                                     0.5-(float(event.size.width*1.25)/float(1000))*0.4,
                                     1,
                                     (event.size.width*1.25)/float(1000)-0.1));
                    hudView.setViewport(sf::FloatRect(0,
                                     0.5-(float(event.size.width*1.25)/float(2000)),
                                     1,
                                     (event.size.width*1.25)/float(1000)*0.1));
                }
                break;
            
            case sf::Event::KeyReleased :
                if(snake.isAlive() && playing)
                {
                    if(event.key.code == sf::Keyboard::Up ||
                       event.key.code == sf::Keyboard::W)
                    {
                        snake.changeDirection(Snake::Direction::up);
                    }
                    else if(event.key.code == sf::Keyboard::Down ||
                            event.key.code == sf::Keyboard::S)
                    {
                        snake.changeDirection(Snake::Direction::down);
                    }
                    else if(event.key.code == sf::Keyboard::Left ||
                            event.key.code == sf::Keyboard::A)
                    {
                        snake.changeDirection(Snake::Direction::left);
                    }
                    else if(event.key.code == sf::Keyboard::Right ||
                            event.key.code == sf::Keyboard::D)
                    {
                        snake.changeDirection(Snake::Direction::right);
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
        }
    }
    
    
    
}
