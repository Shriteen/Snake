#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

class ChangeDifficultySubmenu
{
    private:
        Menu menu;
        sf::FloatRect bounds;
        sf::Font font;
        sf::Color fontColor;
    public:
        ChangeDifficultySubmenu(sf::FloatRect bounds,sf::Color fontColor);
        void draw(sf::RenderWindow &window);
        std::string getSelected();
        void keyHandle(sf::Event &event);
        bool mouseHandle(sf::Event &event,sf::RenderWindow &window);
};
