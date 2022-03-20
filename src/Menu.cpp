#include "headers/Menu.h"
#include<iostream>

Menu::Menu(std::vector<std::string> options,
           sf::Color fontColor,
           float fontSize)
{
    font.loadFromFile("fonts/Coolville.ttf");
    this->fontSize=fontSize;
    this->fontColor=fontColor;
    
    int height = (options.size()*fontSize) + ((options.size()-1)*vertPadding);
    
    this->options.clear();
    for(int i=0; i<options.size(); i++)
    {
        this->options.push_back(sf::Text(options[i],
                                font,
                                fontSize) );
        this->options[i].setFillColor(fontColor);
        
        this->options[i].setPosition( (1080 - this->options[i].getGlobalBounds().width )/2.0,
                                      ((648-height)/2.0) + (i*fontSize) );
    }
    
    selected=0;
}

void Menu::draw(sf::RenderWindow &window)
{
    for(auto &opt: options)
    {
        opt.setStyle(sf::Text::Style::Regular);
        window.draw(opt);
    }
    
    options[selected].setStyle( sf::Text::Style::Underlined);
    window.draw(options[selected]);
}

std::string Menu::getSelected()
{
    return options[selected].getString();
}

void Menu::keyHandle(sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Up :
            case sf::Keyboard::Left :
                if(selected == 0)
                    selected= options.size()-1;
                else
                    selected--;
                break;
            case sf::Keyboard::Down :
            case sf::Keyboard::Right :
                if(selected == options.size()-1)
                    selected= 0;
                else
                    selected++;
                break;
        }
    }
}

void Menu::mouseHandle(sf::Event &event,sf::RenderWindow &window)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        int x = event.mouseButton.x;
        int y = event.mouseButton.y;
        
        for(int i=0;i<options.size();i++)
        {
           if(options[i].getGlobalBounds().contains( window.mapPixelToCoords(sf::Vector2i(x,y) ) ))
           {
               selected=i;
           }
           
        }
    }
}
