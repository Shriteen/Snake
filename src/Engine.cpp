#include "headers/Engine.h"

Engine::Engine():
    window(sf::VideoMode(1080,720),"Snake"),
    bgColor(sf::Color::White),
    borderColor(sf::Color::Black),
    snakeColor(sf::Color::Black),
    foodColor(sf::Color::Red),
    hudTextColor(sf::Color::Magenta),
    border(sf::Vector2f(1080-(2*Pixel::size),720-(2*Pixel::size))),
    hud(hudTextColor),
    playing(true),
    snake(snakeColor,
          sf::Vector2i(1080/2,720/2))
{
    window.setFramerateLimit(60);
    view.reset(sf::FloatRect(0,0,1080,720));
    hudView.reset(sf::FloatRect(0,0,1080,72));
    
    border.setOutlineColor(borderColor);
    border.setOutlineThickness(5);
    border.setPosition(Pixel::size,Pixel::size);
    
    food=new Food(border.getGlobalBounds(),foodColor);
    
    
    font.loadFromFile("fonts/Coolville.ttf");
    startText.setFont(font);
    exitText.setFont(font);
    
    startText.setString("Start");
    startText.setFillColor(hudTextColor);
    startText.setCharacterSize(50);
    sf::FloatRect startBounds = startText.getGlobalBounds();
    
    
    exitText.setString("Exit");
    exitText.setFillColor(hudTextColor);
    exitText.setCharacterSize(50);
    sf::FloatRect exitBounds = exitText.getGlobalBounds();

    startText.setPosition((1080-startBounds.width)/2.0 , (648-startBounds.height-exitBounds.height - 25)/2.0 );
    exitText.setPosition((1080-exitBounds.width)/2.0 , (648-exitBounds.height+25)/2.0 );
}

Engine::~Engine()
{
    delete food;
}

void Engine::start()
{
    adjustViews(window.getSize().x,window.getSize().y);
    
    mainScreen();
    if(!window.isOpen())
        return;
    
    sf::Clock clock;    
    update(1);
    draw();
    while(window.isOpen())
    {
        input();
        
        sf::Time interval=clock.getElapsedTime();
        
        if(interval.asSeconds() > 0.5)
        {
            update(interval.asSeconds());
            clock.restart();
        }
        
        draw();
    }
}

void Engine::adjustViews(int width,int height)
{
    if(float(width)/float(height) > 1.5 )
    {
        view.setViewport(sf::FloatRect( 0.5-(float(height*1.25)/float(2000)),
                         0.1,
                         ((height*1.25)/float(1000)),
                         0.9));
        hudView.setViewport(sf::FloatRect( 0.5-(float(height*1.25)/float(2000)),
                         0,
                         ((height*1.25)/float(1000)),
                         0.1));
    }
    else
    {
        view.setViewport(sf::FloatRect(0,
                         0.5-(float(width*1.25)/float(1000))*0.4,
                         1,
                         (width*1.25)/float(1000)-0.1));
        hudView.setViewport(sf::FloatRect(0,
                         0.5-(float(width*1.25)/float(2000)),
                         1,
                         (width*1.25)/float(1000)*0.1));
    }
}

void Engine::mainScreen()
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed :
                    window.close();
                    break;
                
                case sf::Event::KeyPressed :
                    if(event.key.code == sf::Keyboard::Enter)
                    {
                        return;
                    }
                    else if(event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    break;
                    
                case sf::Event::MouseButtonPressed :
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    if(startText.getGlobalBounds().contains( window.mapPixelToCoords(sf::Vector2i(x,y) ) ))
                    {
                        return;
                    }else if(exitText.getGlobalBounds().contains( window.mapPixelToCoords(sf::Vector2i(x,y) ) ))
                    {
                        window.close();
                    }
                    break;
            }
            
        }
        
        window.clear(bgColor);
        window.draw(startText);
        window.draw(exitText);
        window.display();
    }
}
