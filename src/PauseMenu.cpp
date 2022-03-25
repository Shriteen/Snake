#include "headers/PauseMenu.h"
#include<iostream>

PauseMenu::PauseMenu(sf::FloatRect bounds,sf::Color fontColor,sf::Color bgColor):
    bounds(bounds),
    fontColor(fontColor),
    bgColor(bgColor),
    bg(sf::Vector2f(bounds.width*0.5,bounds.height*0.5)),
    menu(std::vector<std::string>{"Resume","Restart","Exit To Menu"},
         bounds,
         fontColor,
         50)
{
    bg.setFillColor(bgColor);
    bg.setPosition(bounds.width*0.25,bounds.height*0.25);
}

void PauseMenu::draw(sf::RenderWindow &window)
{
    window.draw(bg);
    menu.draw(window);
}

std::string PauseMenu::getSelected()
{
    return menu.getSelected();
}

void PauseMenu::keyHandle(sf::Event &event)
{
    menu.keyHandle(event);
}

bool PauseMenu::mouseHandle(sf::Event &event,sf::RenderWindow &window)
{
    return menu.mouseHandle(event,window);
}
