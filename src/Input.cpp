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
                    view.setViewport(sf::FloatRect( 0.5-(float(event.size.height*1.4)/float(2000)),
                                     0,
                                     (event.size.height*1.4)/float(1000),
                                     1));
                }
                else
                {
                    view.setViewport(sf::FloatRect(0,
                                     0.5-(float(event.size.width*1.4)/float(2000)),
                                     1,
                                     (event.size.width*1.4)/float(1000)));
                }
                break;
        }
    }
    
    
    
}
