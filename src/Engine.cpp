#include "headers/Engine.h"
#include<iostream>

Engine::Engine():
    window(sf::VideoMode(1080,720),"Snake"),
    foodColor(sf::Color::Red),
    hudTextColor(sf::Color::Magenta),
    border(sf::Vector2f(1080-(2*Pixel::size),720-(2*Pixel::size))),
    hud(hudTextColor),
    playing(true),
    snake(sf::Color::Black,
          sf::Vector2i(1080/2,720/2)),
    menu(std::vector<std::string>{"Start","Exit"},
         hudTextColor,
         50)
{
    window.setFramerateLimit(60);
    view.reset(sf::FloatRect(0,0,1080,720));
    hudView.reset(sf::FloatRect(0,0,1080,72));
    
    setColorScheme(colorScheme::light);
    
    border.setOutlineColor(borderColor);
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineThickness(5);
    border.setPosition(Pixel::size,Pixel::size);
    
    food=new Food(border.getGlobalBounds(),foodColor);
    
    
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
                        if(menu.getSelected() == "Start")
                            return;
                        else if(menu.getSelected() == "Exit")
                            window.close();
                    }
                    else if(event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    else
                    {
                        menu.keyHandle(event);
                    }
                    break;
                    
                case sf::Event::MouseButtonPressed :
                    menu.mouseHandle(event,window);
                    if(menu.getSelected() == "Start")
                        return;
                    else if(menu.getSelected() == "Exit")
                        window.close();
                    break;
            }
            
        }
        
        window.clear(bgColor);
        menu.draw(window);
        window.display();
    }
}

void Engine::setColorScheme(colorScheme mode)
{
    switch(mode)
    {
        case colorScheme::light :
            bgColor=sf::Color::White;
            borderColor=sf::Color::Black;
            snake.setColor(sf::Color::Black);
            break;
        case colorScheme::dark :
            bgColor=sf::Color::Black;
            borderColor=sf::Color::White;
            snake.setColor(sf::Color::White);
            break;
    }
    
}
