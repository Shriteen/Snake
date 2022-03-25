#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

class PauseMenu
{
    private:
        Menu menu;
        sf::FloatRect bounds;
        sf::Font font;
        sf::Color fontColor;
        sf::Color bgColor;
        sf::RectangleShape bg;
    public:
        PauseMenu(sf::FloatRect bounds,sf::Color fontColor,sf::Color bgColor);
        void draw(sf::RenderWindow &window);
        std::string getSelected();
        void keyHandle(sf::Event &event);
        bool mouseHandle(sf::Event &event,sf::RenderWindow &window);
};
