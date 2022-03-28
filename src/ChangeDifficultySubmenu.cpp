#include "headers/ChangeDifficultySubmenu.h"
#include<iostream>

ChangeDifficultySubmenu::ChangeDifficultySubmenu(sf::FloatRect bounds,sf::Color fontColor):
    bounds(bounds),
    fontColor(fontColor),
    menu(std::vector<std::string>{"Easy","Medium","Hard"},
         bounds,
         fontColor,
         50)
{
    font.loadFromFile("fonts/Coolville.ttf");
    
}

void ChangeDifficultySubmenu::draw(sf::RenderWindow &window)
{
    menu.draw(window);
}


std::string ChangeDifficultySubmenu::getSelected()
{
    return menu.getSelected();
}

void ChangeDifficultySubmenu::keyHandle(sf::Event &event)
{
    menu.keyHandle(event);
}

bool ChangeDifficultySubmenu::mouseHandle(sf::Event &event,sf::RenderWindow &window)
{
    return menu.mouseHandle(event,window);
}
