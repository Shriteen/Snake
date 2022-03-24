#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

class GameOverDialogue
{
    private:
        Menu menu;
        sf::Text scoreText;
        sf::Text gameOverText;
        sf::FloatRect bounds;
        sf::Font font;
        sf::Color fontColor;
        int score;
    public:
        GameOverDialogue(sf::FloatRect bounds,sf::Color fontColor);
        void draw(sf::RenderWindow &window);
        void setScore(int score);
        std::string getSelected();
        void keyHandle(sf::Event &event);
        bool mouseHandle(sf::Event &event,sf::RenderWindow &window);
};
